#include <stdio.h>
#include <stdlib.h>

#define OUTPUT_SQRT_FILENAME "./output_sqrt_10005.txt"
#define OUTPUT_PI_FILENAME "./output_pi.txt"

char correct_PI[] = "100.024996875781005944792187876357778001595024368696314657135511569650967853864304292311187948499973297755193889369566181110131034907390199103113011081762002108477320948471375552230096402581487736259799653877852069084413851744233085985935136835645595987920074205480337088844259172829146392717997465444956935533235156362393437144446127335342611055181404984709160196901555443838283053099178798153662854042212515559178955190038956796947875043723346722746489250460093586120639339828061620743196368096131561211367739895719588650185901483868174037525897439615657283002590503178179348112792850811520156395905333183399128679070040798208144138650661403742139322413438506761613253152865205380146576761723136982892804149239558827734729922403288124198147483609318126839895071971918461318048544233480880390733620072490500881414107597999636164821033641915553360435756430340707766660642713565508876567843975437232173605543294408637396252210078590415373370915429946528553256356809928978311905701642289829451674374280372642075998274168941932073454763483145971619875572858748271394499338838776972076906473901771085587212329494450488345445586774355027762832963426803670126065682544037049996373303887109318761934550685851280453867661916196580848187831071178393365465303992242115439795512118835899701333648775387501852047514411907333123032485039945658776212162402851793590534659064895808329492152928652374049672982588251159299665800801213366767214842002424748088825310205928377502065113349423291155139211396990832376950292588034073906065968277344107796071193425738646584813663692247979522460598082647829882279313541320548816906444668010637376359531219401240639643462092260769080796407575571627696900854890340453080385020874763749153020334754200876203912764179872814322847598984423091371948875989879180367269921313136439382199701859404661495172469150330386761673134557367955212643284551924937407426736177239130930843881836342397284255918767818644359543252892881376605755569251910816606579608007088543767911270014369706369366502402309598898349221953930358642301117795717560793064600011273782482235064304411696618783579398641799372208466363373506202928806648587022444244769137533942669571242689983443341808904574270440886888090295424069443693097283283316225601612309592725599943012191463953302222363087706621616293581999025262504663181166424798585795286185033834682953776419218559106334723811883384905363717166626166884937983511369937849478839476210537860140208658156787266767580440246249269057879376662865993925748918321116465003665657768297644235786860873956615897625803494821792632272881558840335369808598947851763578242737838928378069269630433760580815389104072523297456072292852863743903989675449108751623036495993014490237102336458010491184906692771955863117653631971306737480509245479719889239671256297464981263947583336423215841581415660066603226268096731123342578466344651775044856263740744483627067449509460063318053615896738991628758416918099804067897759152326062753745252900004555116625647375451417475879359703869177093125426880853657036130009388287008526656201136121402432856847276958482620634300336183990790224595040034165308138542424001353421808026729754319643641893223852430621473711506923187224726459913856123980356781818933370238203874830765137821316515703448807711630456642240243301161783589341187286328279744647778280544580661398122024609265456465174116904712827273688493657895099459701398766060620249066671827049370706299918186411285617544604208903350906436399955537456337672238875516127272371024848284586356646919663932718500704100154877221942162842738643598221151768471992682940077106047611644764046242116908722735943349356431587274967290878781302280628169681835882826540751043368046863713162800800049643803029995605074746365244533629065193917085327053882752738264793831557093592145768836306323937109744668955674017176805296258338557012660453380226503174018053979725541741665348970442198909093467802350289065878057366566185909396120884246276704832010564124763337460497167052378961614118832953096429956014425010275841096937343519359196878201370069286372832588174222325936730419973277798980560325160593393515110199810960941404692590077549777983201214619183803003823707009806606418944668556862535669761677502421811498526736406821434064352932769654077922893345279118066162119999253821360651227093023654396056256708308581822551757028519779917116636940736521956480220018360702208865007200207390827416942385932615361098635995911679227769202520401447623147530352314044393208893319741659164253902425330329227334045740360222148997989569726318979803653015607923668927801082143429548900535798501086680524095378894104254187134411469722745209436715901161336492288124948611644898673240405178257421369966623043419089200167758919802141923345269732196822146623551997345670541236129564839626050767402651256074641372065627630786301479355585927146245780294819187269700493810824952483635780469498739209389180638209298780437878509697139500169752524837026866068883470567197449777207387141415128640788698162262000127463800550084237820344684779388017189898227166298046096475576022387482982116202891047511594880437678071773174724549342068592275016927947140071201196782214251817211317245915219626829764189903575181023548909574848189917719814209657945427875535389061671964026522291187688972409153943062189708157579389595113884968308721383535878770244422386062480171800742299442780789029021658381755495673541016732334437147014188553519050780655522788745175926886135640593597726047146840587677591596885073816534960947199529668997030542291633157607960734461917644889641072438732630933591908025174881662809826957698944073888762295012360727450654852011490429237574669834669351890314309937383417643349662857467570797846626657916204218069553879563963738075310390675647226895344755583082107380378294471293155945886051944521035879746414810476661047506017534470332822719836575805612244631759434670085492205064943514129835232749098817204516022392442027831865323634067180017012717037342444587456043390686110072469590574462929025214210681223700533629144931015927540839505636684229675255221043431100388901971504623720380194403000589448659524727641407723209842676691206388018026725566896532750429467338611350516593815924218506963732201085260858568921524093560854294325830262273775384550311470275606211427535366455002876508472731753070488223947350693997874944459899673160613440232573796700567813099068798523148500004434778333697234980346722189936987748783317897453136431252169072337680131933115437900263657010408387958096895427381850011917868659587799080126212067161598040562523593242725836487531552858831743793325646453165682412857066602986761075919609872641747086085219169359030444982968635154019048628951261674057397364122380861771420768382765068040032839530012492614946124939855938610711208444569598080717806056239166693654044171838940860880379003901356223601493273478761782235210651919502909956264666631025410538379588224401082411520761444637441651083920263501713417367004082985693658356912450096318200129299031121954396829321382132671468647449197374421724141649317523977874252967531973698393012198196994421849125878865647909950951730138711139221035146280855390014437595739457520090650401914293818986850101768758942852154262315634862246201530005447499443128680112395987323059225420619094947377542244176606165996588403175131552442248263957379581435125510055477299698481803268139688832069149691249334854041792172336302661930456987190358891651616535212382967797659257899462986526233192751799816173258781709729629698190811411617780176486419652928129607272499652064893643544396751746783021126669957611202618075996132191677625583285304867454852702082230144005898393684557563315350499336371390250535908700864900860032089083729972287244480254010753677964453013076199044917144691408775374080183969598196157454529634325927020854749663121538424796047115416551133711723828081453524184098541012040469235502366292220682543209664948262502693761595196919784113059653553923483542076421455074654253093842864372610608115099996527916988583490768861482350742389988794652522663608385389015820410622029800312058301721090786108501069459220153824388227710251210163768438746143401214505659651674047974255122627446791495617747815071907265739763856519620952091974374221808073226567833414156279626701887474413858064802908965070842212694392553708091319365140745156605236342007115826260037600399614902888647292751475305532782210381983640027845416881469709274299349125228803765605338755721300772008474171709839531804349709564391350416568836029261682135772861561222496030865631559908843524282757521362792929059448686050754949291369543484151779460692672138945664887236254809170627825972843740567324547657929922960217268957716509347898005260639571683534862373178507925077170684888657764427647140624436532252907744093817200930689930554268201373676379909903799429711813742552478439283201997208721846555114586050135488637475426612118887147143381883705781195721540567413624547166054997996660271067163128708309662194192858525738911012724479998210146883343207056147482006380601324511636082109889740973649476121092643543678145979523784053434134843138774617041324856886130426819736562342691455035500098914193713316906028801925707742696160082860200428195463454614928759046273819842905619818635047474557274216822689909366393342709292574717384016922734414784569049818080522943374977674201165559747584126788276961806833834496690466909912100474963267665200103550137220299863758056758394749161164381649407841076878021232223083869062488622608792936055193310337993575479393353677867207049622242901006336092237497389296147922168041313406400429930173860907759711259401357376879070065789572500049896507575033182362697926762636707875452860084873446905231322377271852551085448533514177372694566657982375942458270232225312593785695490109262634419020266890846997400705742403473320031027532572085235124387411277776443129306543044458335303614863668600953508364413878394831481475518324322624812635306722797566434487796958240126311666411017621955092822734602802581081347331624372447591777959014612892964";
char correct_root[] = "3.14159265358979323846264338327950288419716939937510582097494459230781640628620899862803482534211706798214808651328230664709384460955058223172535940812848111745028410270193852110555964462294895493038196442881097566593344612847564823378678316527120190914564856692346034861045432664821339360726024914127372458700660631558817488152092096282925409171536436789259036001133053054882046652138414695194151160943305727036575959195309218611738193261179310511854807446237996274956735188575272489122793818301194912983367336244065664308602139494639522473719070217986094370277053921717629317675238467481846766940513200056812714526356082778577134275778960917363717872146844090122495343014654958537105079227968925892354201995611212902196086403441815981362977477130996051870721134999999837297804995105973173281609631859502445945534690830264252230825334468503526193118817101000313783875288658753320838142061717766914730359825349042875546873115956286388235378759375195778185778053217122680661300192787661119590921642019893809525720106548586327886593615338182796823030195203530185296899577362259941389124972177528347913151557485724245415069595082953311686172785588907509838175463746493931925506040092770167113900984882401285836160356370766010471018194295559619894676783744944825537977472684710404753464620804668425906949129331367702898915210475216205696602405803815019351125338243003558764024749647326391419927260426992279678235478163600934172164121992458631503028618297455570674983850549458858692699569092721079750930295532116534498720275596023648066549911988183479775356636980742654252786255181841757467289097777279380008164706001614524919217321721477235014144197356854816136115735255213347574184946843852332390739414333454776241686251898356948556209921922218427255025425688767179049460165346680498862723279178608578438382796797668145410095388378636095068006422512520511739298489608412848862694560424196528502221066118630674427862203919494504712371378696095636437191728746776465757396241389086583264599581339047802759009946576407895126946839835259570982582262052248940772671947826848260147699090264013639443745530506820349625245174939965143142980919065925093722169646151570985838741059788595977297549893016175392846813826868386894277415599185592524595395943104997252468084598727364469584865383673622262609912460805124388439045124413654976278079771569143599770012961608944169486855584840635342207222582848864815845602850601684273945226746767889525213852254995466672782398645659611635488623057745649803559363456817432411251507606947945109659609402522887971089314566913686722874894056010150330861792868092087476091782493858900971490967598526136554978189312978482168299894872265880485756401427047755513237964145152374623436454285844479526586782105114135473573952311342716610213596953623144295248493718711014576540359027993440374200731057853906219838744780847848968332144571386875194350643021845319104848100537061468067491927819119793995206141966342875444064374512371819217999839101591956181467514269123974894090718649423196156794520809514655022523160388193014209376213785595663893778708303906979207734672218256259966150142150306803844773454920260541466592520149744285073251866600213243408819071048633173464965145390579626856100550810665879699816357473638405257145910289706414011097120628043903975951567715770042033786993600723055876317635942187312514712053292819182618612586732157919841484882916447060957527069572209175671167229109816909152801735067127485832228718352093539657251210835791513698820914442100675103346711031412671113699086585163983150197016515116851714376576183515565088490998985998238734552833163550764791853589322618548963213293308985706420467525907091548141654985946163718027098199430992448895757128289059232332609729971208443357326548938239119325974636673058360414281388303203824903758985243744170291327656180937734440307074692112019130203303801976211011004492932151608424448596376698389522868478312355265821314495768572624334418930396864262434107732269780280731891544110104468232527162010526522721116603966655730925471105578537634668206531098965269186205647693125705863566201855810072936065987648611791045334885034611365768675324944166803962657978771855608455296541266540853061434443185867697514566140680070023787765913440171274947042056223053899456131407112700040785473326993908145466464588079727082668306343285878569830523580893306575740679545716377525420211495576158140025012622859413021647155097925923099079654737612551765675135751782966645477917450112996148903046399471329621073404375189573596145890193897131117904297828564750320319869151402870808599048010941214722131794764777262241425485454033215718530614228813758504306332175182979866223717215916077166925474873898665494945011465406284336639379003976926567214638530673609657120918076383271664162748888007869256029022847210403172118608204190004229661711963779213375751149595015660496318629472654736425230817703675159067350235072835405670403867435136222247715891504953098444893330963408780769325993978054193414473774418426312986080998886874132604721569516239658645730216315981931951673538129741677294786724229246543668009806769282382806899640048243540370141631496589794092432378969070697794223625082216889573837986230015937764716512289357860158816175578297352334460428151262720373431465319777741603199066554187639792933441952154134189948544473456738316249934191318148092777710386387734317720754565453220777092120190516609628049092636019759882816133231666365286193266863360627356763035447762803504507772355471058595487027908143562401451718062464362679456127531813407833033625423278394497538243720583531147711992606381334677687969597030983391307710987040859133746414428227726346594704745878477872019277152807317679077071572134447306057007334924369311383504931631284042512192565179806941135280131470130478164378851852909285452011658393419656213491434159562586586557055269049652098580338507224264829397285847831630577775606888764462482468579260395352773480304802900587607582510474709164396136267604492562742042083208566119062545433721315359584506877246029016187667952406163425225771954291629919306455377991403734043287526288896399587947572917464263574552540790914513571113694109119393251910760208252026187985318877058429725916778131496990090192116971737278476847268608490033770242429165130050051683233643503895170298939223345172201381280696501178440874519601212285993716231301711444846409038906449544400619869075485160263275052983491874078668088183385102283345085048608250393021332197155184306354550076682829493041377655279397517546139539846833936383047461199665385815384205685338621867252334028308711232827892125077126294632295639898989358211674562701021835646220134967151881909730381198004973407239610368540664319395097901906996395524530054505806855019567302292191393391856803449039820595510022635353619204199474553859381023439554495977837790237421617271117236434354394782218185286240851400666044332588856986705431547069657474585503323233421073015459405165537906866273337995851156257843229882737231989875714159578111963583300594087306812160287649628674460477464915995054973742562690104903778198683593814657412680492564879855614537234786733039046883834363465537949864192705638729317487233208376011230299113679386270894387993620162951541337142489283072201269014754668476535761647737946752004907571555278196536213239264061601363581559074220202031872776052772190055614842555187925303435139844253223415762336106425063904975008656271095359194658975141310348227693062474353632569160781547818115284366795706110861533150445212747392454494542368288606134084148637767009612071512491404302725386076482363414334623518975766452164137679690314950191085759844239198629164219399490723623464684411739403265918404437805133389452574239950829659122850855582157250310712570126683024029295252201187267675622041542051618416348475651699981161410100299607838690929160302884002691041407928862150784245167090870006992821206604183718065355672525325675328612910424877618258297651579598470356222629348600341587229805349896502262917487882027342092222453398562647669149055628425039127577102840279980663658254889264880254566101729670266407655904290994568150652653053718294127033693137851786090407086671149655834343476933857817113864558736781230145876871266034891390956200993936103102916161528813843790990423174733639480457593149314052976347574811935670911013775172100803155902485309066920376719220332290943346768514221447737939375170344366199104033751117354719185504644902636551281622882446257591633303910722538374218214088350865739177150968288747826569959957449066175834413752239709683408005355984917541738188399944697486762655165827658483588453142775687900290951702835297163445621296404352311760066510124120065975585127617858382920419748442360800719304576189323492292796501987518721272675079812554709589045563579212210333466974992356302549478024901141952123828153091140790738602515227429958180724716259166854513331239480494707911915326734302824418604142636395480004480026704962482017928964766975831832713142517029692348896276684403232609275249603579964692565049368183609003238092934595889706953653494060340216654437558900456328822505452556405644824651518754711962184439658253375438856909411303150952617937800297412076651479394259029896959469955657612186561967337862362561252163208628692221032748892186543648022967807057656151446320469279068212073883778142335628236089632080682224680122482611771858963814091839036736722208883215137556003727983940041529700287830766709444745601345564172543709069793961225714298946715435784687886144458123145935719849225284716050492212424701412147805734551050080190869960330276347870810817545011930714122339086639383395294257869050764310063835198343893415961318543475464955697810382930971646514384070070736041123735998434522516105070270562352660127648483084076118301305279320542746286540360367453286510570658748822569815793678976697422057505968344086973502014102067235850200724522563265134105592401902742162484391403599895353945909440704691209140938700126456001623742880210927645793106579229552498872758461012648369998922569596881592056001016552563756785667227966198857827948488558343975187445455129656344348039664205579829368043522027709842942325330225763418070394769941597915945300697521482933665556615678736400536665641654732170439035213295435291694145990416087532018683793702348886894791510716378529023452924407736594956305100742108714261349745956151384987137570471017879573104229690666702144986374645952808243694457897723300487647652413390759204340196340391147320233807150952220106825634274716460243354400515212669324934196739770415956837535551667302739007497297363549645332888698440611964961627734495182736955882207573551766515898551909866653935494810688732068599075407923424023009259007017319603622547564789406475483466477604114632339056513433068449539790709030234604614709616968868850140834704054607429586991382966824681857103188790652870366508324319744047718556789348230894310682870272280973624809399627060747264553992539944280811373694338872940630792615959954626246297070625948455690347119729964090894180595343932512362355081349490043642785271383159125689892951964272875739469142725343669415323610045373048819855170659412173524625895487301676002988659257866285612496655235338294287854253404830833070165372285635591525347844598183134112900199920598135220511733658564078264849427644113763938669248031183644536985891754426473998822846218449008777697763127957226726555625962825427653183001340709223343657791601280931794017185985999338492354956400570995585611349802524990669842330173503580440811685526531170995708994273287092584878944364600504108922669178352587078595129834417295351953788553457374260859029081765155780390594640873506123226112009373108048548526357228257682034160504846627750450031262008007998049254853469414697751649327095049346393824322271885159740547021482897111777923761225788734771881968254629812686858170507402725502633290449762778944236216741191862694396506715157795867564823993917604260176338704549901761436412046921823707648878341968968611815581587360629386038101712158552726683008238340465647588040513808016336388742163714064354955618689641122821407533026551004241048967835285882902436709048871181909094945331442182876618103100735477054981596807720094746961343609286148494178501718077930681085469000944589952794243981392135055864221964834915126390128038320010977386806628779239718014613432445726400973742570073592100315415089367930081699805365202760072774967458400283624053460372634165542590276018348403068113818551059797056640075094260878857357960373245141467867036880988060971642584975951380693094494015154222219432913021739125383559150310033303251117491569691745027149433151558854039221640972291011290355218157628232831823425483261119128009282525619020526301639114772473314857391077758744253876117465786711694147764214411112635835538713610110232679877564102468240322648346417663698066378576813492045302240819727856471983963087815432211669122464159117767322532643356861461865452226812688726844596844241610785401676814208088502800541436131462308210259417375623899420757136275167457318918945628352570441335437585753426986994725470316566139919996826282472706413362221789239031760854289437339356188916512504244040089527198378738648058472689546243882343751788520143956005710481194988423906061369573423155907967034614914344788636041031823507365027785908975782727313050488939890099239135033732508559826558670892426124294736701939077271307068691709264625484232407485503660801360466895118400936686095463250021458529309500009071510582362672932645373821049387249966993394246855164832611341461106802674466373343753407642940266829738652209357016263846485285149036293201991996882851718395366913452224447080459239660281715655156566611135982311225062890585491450971575539002439315351909021071194573002438801766150352708626025378817975194780610137150044899172100222013350131060163915415895780371177927752259787428919179155224171895853616805947412341933984202187456492564434623925319531351033114763949119950728584306583619353693296992898379149419394060857248639688369032655643642166442576079147108699843157337496488352927693282207629472823815374099615455987982598910937171262182830258481123890119682214294576675807186538065064870261338928229949725745303328389638184394477077940228435988341003583854238973542439564755568409522484455413923941000162076936368467764130178196593799715574685419463348937484391297423914336593604100352343777065888677811394986164787471407932638587386247328896456435987746676384794665040741118256583788784548581489629612739984134427260860618724554523606431537101127468097787044640947582803487697589483282412392929605829486191966709189580898332012103184303401284951162035342801441276172858302435598300320420245120728725355811958401491809692533950757784000674655260314461670508276827722235341911026341631571474061238504258459884199076112872580591139356896014316682831763235673254170734208173322304629879928049085140947903688786878949305469557030726190095020764334933591060245450864536289354568629585313153371838682656178622736371697577418302398600659148161640494496501173213138957470620884748023653710311508984279927544268532779743113951435741722197597993596852522857452637962896126915723579866205734083757668738842664059909935050008133754324546359675048442352848747014435454195762584735642161981340734685411176688311865448937769795665172796623267148103386439137518659467300244345005449953997423723287124948347060440634716063258306498297955101095418362350303094530973358344628394763047756450150085075789495489313939448992161255255977014368589435858775263796255970816776438001254365023714127834679261019955852247172201777237004178084194239487254068015560359983905489857235467456423905858502167190313952629445543913166313453089390620467843877850542393905247313620129476918749751910114723152893267725339181466073000890277689631148109022097245207591672970078505807171863810549679731001678708506942070922329080703832634534520380278609905569001341371823683709919495164896007550493412678764367463849020639640197666855923356546391383631857456981471962108410809618846054560390384553437291414465134749407848844237721751543342603066988317683310011331086904219390310801437843341513709243530136776310849135161564226984750743032971674696406665315270353254671126675224605511995818319637637076179919192035795820075956053023462677579439363074630569010801149427141009391369138107258137813578940055995001835425118417213605572752210352680373572652792241737360575112788721819084490061780138897107708229310027976659358387589093956881485602632243937265624727760378908144588378550197028437793624078250527048758164703245812908783952324532378960298416692254896497156069811921865849267704039564812781021799132174163058105545988013004845629976511212415363745150056350701278159267142413421033015661653560247338078430286552572227530499988370153487930080626018096238151613669033411113865385109193673938352293458883225508870645075394739520439680790670868064450969865488016828743437861264538158342807530618454859037982179945996811544197425363443996029025100158882721647450068207041937615845471231834600726293395505482395571372568402322682130124767945226448209102356477527230820810635188991526928891084555711266039650343978962782500161101532351605196559042118449499077899920073294769058685778787209829013529566139788848605097860859570177312981553149516814671769597609942100361835591387778176984587581044662839988060061622984861693533738657877359833616133841338536842119789389001852956919678045544828584837011709672125353387586215823101331038776682721157269495181795897546939926421979155233857662316762754757035469941489290413018638611943919628388705436777432242768091323654494853667680000010652624854730558615989991401707698385483188750142938908995068545307651168033373222651756622075269517914422528081651716677667279303548515420402381746089232839170327542575086765511785939500279338959205766827896776445318404041855401043513483895312013263783692835808271937831265496174599705674507183320650345566440344904536275600112501843356073612227659492783937064784264567633881880756561216896050416113903906396016202215368494109260538768871483798955999911209916464644119185682770045742434340216722764455893301277815868695250694993646101756850601671453543158148010545886056455013320375864548584032402987170934809105562116715468484778039447569798042631809917564228098739987669732376957370158080682290459921236616890259627304306793165311494017647376938735140933618332161428021497633991898354848756252987524238730775595559554651963944018218409984124898262367377146722606163364329640633572810707887581640438148501884114318859882769449011932129682715888413386943468285900666408063140777577257056307294004929403024204984165654797367054855804458657202276378404668233798528271057843197535417950113472736257740802134768260450228515797957976474670228409995616015691089038458245026792659420555039587922981852648007068376504183656209455543461351341525700659748819163413595567196496540321872716026485930490397874895890661272507948282769389535217536218507962977851461884327192232238101587444505286652380225328438913752738458923844225354726530981715784478342158223270206902872323300538621634798850946954720047952311201504329322662827276321779088400878614802214753765781058197022263097174950721272484794781695729614236585957820908307332335603484653187302930266596450137183754288975579714499246540386817992138934692447419850973346267933210726868707680626399193619650440995421676278409146698569257150743157407938053239252394775574415918458215625181921552337096074833292349210345146264374498055961033079941453477845746999921285999993996122816152193148887693880222810830019860165494165426169685867883726095877456761825072759929508931805218729246108676399589161458550583972742098090978172932393010676638682404011130402470073508578287246271349463685318154696904669686939254725194139929146524238577625500474852954768147954670070503479995888676950161249722820403039954632788306959762493615101024365553522306906129493885990157346610237122354789112925476961760050479749280607212680392269110277722610254414922157650450812067717357120271802429681062037765788371669091094180744878140490755178";

char *Arr;

int main()
{
    printf("Select one option\n");
    printf("1.Check accuracy of sqrt(10005)\n2.Check accuracy of PI\n");
    int choice;
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
    {
        FILE *ptr;
        ptr = fopen(OUTPUT_SQRT_FILENAME, "r"); // example.txt is the file which contains the input data
        int sz = 0;                             // indicating the size of the array,increased as per user's input
        while (!feof(ptr))
        {
            int x;
            fscanf(ptr, "%c", &x);
            Arr = (char *)realloc(Arr, (++sz) * sizeof(char)); // reallocating the size every time as size is unknown

            Arr[sz - 1] = x;
        }
        // printf("The size of the array is : %d\n", sz);

        int correct = -4;
        for (int i = 0; i < sz; i++)
        {
            if (Arr[i] != correct_PI[i])
            {
                break;
            }
            else
            {
                correct++;
            }
        }

        printf("value is correct upto %d decimal places\n", correct);
        break;
        
    }
    case 2:
    {
        FILE *ptr;
        ptr = fopen(OUTPUT_PI_FILENAME, "r");  
        int sz = 0;                             
        while (!feof(ptr))
        {
            int x;
            fscanf(ptr, "%c", &x);
            Arr = (char *)realloc(Arr, (++sz) * sizeof(char)); // reallocating the size every time as size is unknown

            Arr[sz - 1] = x;
        }
        // printf("The size of the array is : %d\n", sz);

        int correct = -2;
        for (int i = 0; i < sz; i++)
        {
            if (Arr[i] != correct_root[i])
            {
                break;
            }
            else
            {
                correct++;
            }
        }

        printf("value is correct upto %d decimal places\n", correct);
    }
    }
}

