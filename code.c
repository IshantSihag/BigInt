#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define BASE 1000000000000000000ULL; // 1e18
#define HALFBASE 1000000000ULL

struct BigIntStruct
{
    short int sign;
    unsigned int len;
    unsigned long long *d;
};

struct ComplexStruct
{
    float real;
    float imag;
} * n1, *n2;

typedef struct BigIntStruct *BigInt;
typedef struct BigIntStruct BigIntObj;

typedef struct ComplexStruct *Complex;
typedef struct ComplexStruct ComplexObj;

typedef unsigned long long llu;

Complex new_comp()
{
    Complex new;
    new = (Complex)malloc(sizeof(ComplexObj));

    return new;
}

float real_part(Complex a)
{
    return a->real;
}

float imag_part(Complex a)
{
    return a->imag;
}
Complex conjugate(Complex a)
{
    Complex c = new_comp();
    c->real = a->real;
    if (a->imag == 0)
    {
        c->imag = a->imag;
    }
    else
        c->imag = (-1) * (a->imag);
    return c;
}

float modulus(Complex a)
{
    return pow(a->real, 2) + pow(a->imag, 2);
}
Complex add_Comp(Complex a, Complex b)
{
    Complex c;
    c = new_comp();
    c->real = (a->real) + (b->real);
    c->imag = (a->imag) + (b->imag);
    return c;
}

Complex subtract_complex(Complex a, Complex b)
{
    Complex c;
    c = new_comp();
    c->real = a->real - b->real;
    c->imag = a->imag - (b->imag);

    return c;
}

Complex multiply_complex(Complex a, Complex b)
{
    Complex c = new_comp();
    c->real = (a->real * b->real) - (a->imag * b->imag);
    c->imag = (a->real * b->imag) + (a->imag * b->real);

    return c;
}

Complex divide_complex(Complex a, Complex b)
{
    Complex c = new_comp();

    c->real = real_part(multiply_complex(a, conjugate(b))) / modulus(b);
    c->imag = imag_part(multiply_complex(a, conjugate(b))) / modulus(b);

    return c;
}

BigInt new_BigInt(const unsigned int length)
{
    BigInt b = (BigInt)malloc(sizeof(BigIntObj));
    b->sign = 1;
    b->len = length;
    b->d = (llu *)malloc(length * sizeof(llu));
    return b;
}

void print_Comp(Complex a)
{
    if (a->imag >= 0)
        printf("%g + %gi\n", (a->real), (a->imag));
    else
        printf("%g - %gi\n", (a->real), -(a->imag));
}

int max(int x, int y)
{
    return x > y ? x : y;
}

void set_zero(BigInt b)
{
    for (unsigned int i = 0; i < b->len; i++)
        b->d[i] = 0;
}

void free_BigInt(BigInt b)
{
    free(b->d);
    free(b);
}

void print_BigInt(BigInt b)
{
    printf("%c", b->sign == 1 ? '+' : '-');

    int i = b->len;
    while (--i > 0 && b->d[i] == 0)
        ;

    printf("%llu", b->d[i--]);

    while (i >= 0)
        printf("%018llu", b->d[i--]);

    printf("\n");
}

void increase_size(BigInt b, const unsigned int delta_len)
{
    b->d = (llu *)realloc(b->d, sizeof(llu) * (b->len + delta_len));
    b->len += delta_len;
    for (int i = b->len - delta_len; i < b->len; i++)
        b->d[i] = 0;
}

// void increase_size1(BigInt b) {
//     increase_size(b, b->len);
// }
BigInt Add(const BigInt a, const BigInt b)
{
    BigInt c = new_BigInt(1 + max(a->len, b->len));
    set_zero(c);
    llu carry = 0;
    for (unsigned int i = 0; i < c->len - 1; i++)
    {
        c->d[i] = a->d[i] + b->d[i] + carry;
        carry = c->d[i] / BASE;
        c->d[i] %= BASE;
    }
    if (carry > 0)
    {
        c->d[c->len - 1] = carry;
    }
    return c;
}

int isPrime(int n)  {
    if (n <= 1)  return 0;
    if (n <= 3)  return 1;
    if (n%2 == 0 || n%3 == 0) return 0;
    
    for (int i=5; i*i<=n; i=i+6)
        if (n%i == 0 || n%(i+2) == 0)
               return 0;
    return 1;
}

BigInt Subtract(const BigInt a, const BigInt b)
{
    BigInt c = new_BigInt(max(a->len, b->len));
    set_zero(c);
    llu carry = 0;
    for (unsigned int i = 0; i < c->len; i++)
    {
        c->d[i] = a->d[i] - b->d[i] - carry;
        carry = c->d[i] / BASE;
        c->d[i] %= BASE;
    }
    return c;
}

void _MUL_(llu x, llu y, llu *carry, llu *result)
{
    /*
    Multiplies x and y, and stores the product in result, and excess value in carry.
    The value stored in carry is added to result before multiplication.
    The value stored in result is incremented, not overwritten.
    */

    llu x0 = x % HALFBASE,
        x1 = x / HALFBASE,
        y0 = y % HALFBASE,
        y1 = y / HALFBASE,
        excess = x1 * y0 + x0 * y1;

    // Note the += here, to add to the previous value; Also note that the previous carry is added to this because carry will be reset to new carry
    *result += x0 * y0 + (excess % HALFBASE) * HALFBASE + (*carry);

    // No += here because carry will be recalculated
    *carry = x1 * y1 + excess / HALFBASE + (*result) / BASE;

    *result %= BASE;
}

BigInt Multiply(const BigInt a, const BigInt b)
{
    BigInt c = new_BigInt(a->len + b->len);
    c->sign = 1 - a->sign ^ b->sign;
    llu carry;
    set_zero(c);
    for (unsigned int i = 0; i < a->len; i++)
    {
        carry = 0;
        for (unsigned int j = 0; j < b->len; j++)
        {
            _MUL_(a->d[i], b->d[j], &carry, &(c->d[i + j]));
            // _MUL_ exactly does the below 3 operations without overflow
            // c->d[i + j] += a->d[i] * b->d[j] + carry;
            // carry = c->d[i + j] / BASE;
            // c->d[i + j] %= BASE;
        }
        c->d[i + b->len] = carry;
    }
    return c;
}

// int compare(const BigInt a, const BigInt b)
// {
//     BigInt c=Subtract(a,b);
    
// }
void Increment(const BigInt a, const BigInt delta)
{
    if (a->len <= delta->len)
    {
        increase_size(a, delta->len - a->len + 1);
    }
    llu carry = 0;
    for (unsigned int i = 0; i < delta->len; i++)
    {
        a->d[i] += delta->d[i] + carry;
        carry = a->d[i] / BASE;
        a->d[i] %= BASE;
    }
    for (unsigned int i = delta->len; i < a->len; i++)
    {
        a->d[i] += carry;
        carry = a->d[i] / BASE;
        a->d[i] %= BASE;
    }
}

BigInt take_input() // function to take input from user by string
{
    char *arr;
    arr = (char *)malloc(2 * sizeof(char));
    int count = 0;
    int szalloc = 2;
    char c = ' ';
    int sgn = 1;
    while (c != '\n')
    {
        if (count == szalloc - 1)
        {

            arr = (char *)realloc(arr, 2 * szalloc * sizeof(char));
            szalloc *= 2;
        }

        scanf("%c", &c);
        if (count == 0)
        {
            if (c == '+' || c == '-')
            {
                if (c == '-')
                {
                    sgn = 0;
                }
                continue;
            }
        }
        arr[count] = c;

        count++;
    }

    int lenreq = count / 18;
    if (count % 18 != 0)
    {
        lenreq++;
    }
    BigInt x = new_BigInt(lenreq);
    set_zero(x);
    int j = 0;
    while (count != 0)
    {
        llu tmp = 0;
        if (count < 18)
        {
            for (int i = 0; i < count - 1; i++)
            {
                tmp = 10 * tmp + (arr[i] - '0');
                // printf("%d ",arr[i]-'0');
            }
            x->d[j] = tmp;
            j++;
            count = 0;
            // printf("\ntmp %d \n",arr[3]-'0');
        }
        else
        {
            for (int i = count - 19; i < count - 1; i++)
            {
                tmp = 10 * tmp + (arr[i] - '0');
            }
            count -= 18;
            x->d[j] = tmp;
            j++;
        }
    }
    x->sign = sgn;
    return x;
}

int main()
{
    // printf("Enter two number for multiplication\n");
    BigInt y=take_input();
    print_BigInt(y);
    BigInt z=take_input();
    print_BigInt(z);

    // printf("\n%d ",Subtract(y,z));
    BigInt c=Subtract(y,z);
    print_BigInt(c);

    // BigInt ans=Multiply(y,z);
    // printf("Your answer after multiplication is \n");
    // print_BigInt(ans);

    // Complex n1,n2;
    // long double x1=1.00,x2=2.00,x3.00=4,x4.00=5;
    // scanf("%Lf%Lf%Lf%Lf",&x1,&x2,&x3,&x4);

    // n1 = new_comp();
    // n2 = new_comp();
    // (n1->real) = 2;
    // (n2->real) = 4;

    // (n1->imag) = 3;
    // (n2->imag) = 7;

    // print_Comp(n1);
    // print_Comp(n2);
    // Complex n3 = (Complex)malloc(sizeof(ComplexObj));
    // n3 = divide_complex(n1, n2);

    // print_Comp(n3);
    // // print_Comp(modulus(n1));
    // printf("%d\n", modulus(n1));
    // print_Comp(conjugate(n3));

    // printf("%d\n", x->len);

    ;

    return 0;
}