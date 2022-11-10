# Big Integer Implementation in C
## Chudnovsky Algorithm for High-Precision Computation of Pi

This project presents an implementation of the Chudnovsky algorithm, a renowned method for calculating the value of Pi (`π`) with high precision and efficiency through the use of an infinite series. The program supports arbitrary-precision arithmetic, enabling complex calculations on big integers, fractions, and complex numbers, and includes the Newton-Raphson algorithm to enhance computational accuracy.

## Key Features

- **Big Integer Arithmetic:** Supports a comprehensive suite of operations, including addition, subtraction, multiplication, division, modulus, greatest common divisor (GCD), power, and factorial.
- **Complex Number Arithmetic:** Facilitates addition, subtraction, multiplication, division, and conjugate operations on complex numbers.
- **Fraction Operations:** Provides addition, subtraction, multiplication, division, and simplification of fractions to their simplest forms.
- **Chudnovsky Algorithm for Pi Calculation:** Computes the value of Pi with a user-specified precision using the Chudnovsky formula.
- **Newton-Raphson Method:** Accurately computes the square root of 10005, an essential step in the Chudnovsky formula.

## Getting Started

### Prerequisites

To run this project, ensure that a C/C++ compiler is installed. The program relies solely on standard C libraries, requiring no additional dependencies.

### Compilation and Execution

Compile the program with the following command:
```sh
gcc main.c -o main
```

To execute the compiled program

For Linux users, Run the command:
```sh
./main.out
```

For Windows users, Run the command:
```sh
./main.exe
```


### Program Menu

Upon execution, the program displays a menu with the following functionalities:

1. **Big Integer Operations:**
   - Addition, Subtraction, Multiplication, Division, Decimal Division, Modulus, GCD, Power, Factorial.

2. **Complex Number Operations:**
   - Addition, Subtraction, Multiplication, Division, Conjugate.

3. **Fraction Operations:**
   - Addition, Subtraction, Multiplication, Division, Simplification to Simplest Form.

4. **Pi Computation:**
   - Square root calculation of 10005 using Newton-Raphson.
   - Pi calculation through the Chudnovsky algorithm.

5. **Additional Features:**
   - Decimal precision setting.
   - Program exit.

## Chudnovsky Algorithm for Pi Calculation

The Chudnovsky algorithm is a highly efficient and precise method for calculating Pi. This implementation allows for calculating Pi as a fraction, which can then be converted to its decimal representation as required.

### Steps to Use the Chudnovsky Algorithm

1. Choose the menu option for Pi computation.
2. Enter the desired number of terms for the calculation. Increasing the number of terms will increase the accuracy but will also require more computational resources.
3. Optionally, the resulting value of Pi can be output to a file in its decimal form.

## Performance and Precision

- High-precision arithmetic and large integer calculations are computationally intensive.
- The program employs arbitrary-precision arithmetic to ensure accurate results for both large integers and fractions.

## Contributing

Contributions are encouraged! Feel free to fork the repository and submit pull requests for improvements or additional features.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for more details.

## Acknowledgments

This project acknowledges the utility of the Chudnovsky algorithm for its precision in Pi computation, as well as the support for arbitrary-precision arithmetic, enabling large-scale calculations and enhanced functionality.