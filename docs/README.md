# fire 

![alt tag](https://raw.githubusercontent.com/FireFather/fire-zero/master/bitmaps/nnue-gui.png)

**fire self-play nnue** (poora kod aur tippaniyaan jald hee hindee mein upalabdh hongee)

## visheshataen
- c++20
- vindoz aur linaks
- yooseeaee
- 64-bit
- esemapee (256 dhaage tak)
- konfigar karane yogy haish (1024 jeebee tak)
- vichaar karen
- malteepeevee
- vishleshan (anant) mod
- shataranja960 (phishar raindam)
- sizeejee tebalabes
- samaayojy avamaanana ​​seting
- tejee se poorn aur vibhaajit karen
- bench (teeteedee samay-se-gaharaee ganana shaamil hai)
- taimastaimpd bench, parft, aur divaid log failen
- std::uniquai_lochk<std::mutaix> ka upayog karake esinkronas kout (achout) klaas
- yooseeaee vikalp injanamod raindam w/uniform_raial_distribution & maisainnai_twistair_ainginai
- ek adviteey nnuai (aadhaakp_256x2-32-32) moolyaankan ka upayog karata hai
- tez alpha-beeta khoj
- vaikalpik prayogaatmak emaseeteees-yooseetee khoj
 (monte kaarlo tree sarch w/pedon par laagoo ooparee konphidens baunds) shuddh/koee nyoonatam adhikatam nahin

**fire-9 ab upalabdh hai**

|                                       |    |       |                    |      |
| ------------------------------------- |--- | ----- | ------------------ | ---- |
|                                       |    | khel |(+jeet, = dra, -haar)| (%)  |
|    fire-9_x64_bmi2  			|3460| 16384 | (+5968,=4937,-5479)|51.5 %|
|    vs.                                |     |      |                    |      |
|    stockfish-15                 	|3861|   863 | (+715,=135,-13)    |90.7 %|
|    komodo-dragon-3.1           	|3838|   863 | (+702,=141,-20)    |89.5 %|
|    berserk-9                   	|3754|   863 | (+631,=190,-42)    |84.1 %|
|    koivisto_8.0                 	|3637|   863 | (+501,=261,-101)   |73.2 %|
|    rubiChess-20220813          	|3564|   863 | (+386,=338,-139)   |64.3 %|
|    seer-v2.5                    	|3504|   862 | (+322,=324,-216)   |56.1 %|
|    rofChade-3.0                 	|3492|   862 | (+302,=336,-224)   |54.5 %|
|    slow64-2.9                   	|3452|   863 | (+254,=336,-273)   |48.9 %|
|    rebel-15.1                   	|3450|   862 | (+245,=348,-269)   |48.6 %|
|    wasp-6.00                   	|3395|   862 | (+207,=291,-364)   |40.9 %|
|    fire-8242022                	|3384|   862 | (+195,=290,-377)   |39.4 %|
|    nemorino-6.00                	|3374|   862 | (+156,=344,-362)   |38.1 %|
|    igel-3.1.0                   	|3334|   862 | (+122,=323,-417)   |32.9 %|
|    ethereal-12.75              	|3331|   862 | (+158,=244,-460)   |32.5 %|
|    clover-3.1                   	|3296|   862 | (+147,=194,-521)   |28.3 %|
|    minic-3.24                   	|3290|   862 | (+106,=264,-492)   |27.6 %|
|    xiphos-0.6                   	|3266|   862 | (+124,=184,-554)   |25.1 %|
|    tucano-10.00                 	|3266|   862 | (+99,=234,-529)    |25.1 %|
|    marvin-6.0.0                 	|3233|   862 | (+107,=160,-595)   |21.7 %|

khel poore hue = 16384 of 16384 (ausat gem kee lambaee = 12.627 sec)

Settings = Gauntlet/32MB/1000ms+100ms/M 500cp for 6 moves, D 120 moves/EPD:book.epd(31526)

## upakaranon ka istemaal:

- sv-ple gems kee peedhee ke lie injan
  - fire 8.2 https://github.com/FireFather/fire-HCE
- selph-ple gem chalaane ke lie eplikeshan
  - cutechess-cli https://github.com/cutechess/cutechess
- peejeeen phailon se phen sthiti aur moolyaankan deta praapt karane aur saade paath mein parivartit karane ke lie aavedan
  - karm upakaran se nnuai-aixtracht.aixai https://outskirts.altervista.org/forum/viewtopic.php?t=2009
- enenayoo prashikshan satr prabandhan ke lie vindoz epleekeshan
  - nnue-gui https://github.com/FireFather/nnue-gui
- mool nodachip shogee nyooral netavark kaaryaanvayan ka anukoolit port
  - sf-nnue https://github.com/FireFather/sf-nnue-aio
- peejeeenes se phen kee sthiti aur jaanakaaree nikaalane ke lie enenayoo-eksatraikt dvaara upayog kiya jaane vaala eplikeshan
  - pgn-extract https://www.cs.kent.ac.uk/people/staff/djb/pgn-extract/
- enenayoo banaam enenayoo aadi ke pareekshan ke lie aavedan.
  - little blitzer http://www.kimiensoftware.com/software/chess/littleblitzer
- peejeeen failon se dupliket gem hataane ke lie upayogita
  - chessbase 16 64-bit https://shop.chessbase.com/en/products/chessbase_16_fritz18_bundle
- vividh upayogitaen: trunatai.aixai (buk plaee seema kholana) aur gemasplit.aixai (peejeeen ko kaee bhaagon mein todana)
  - 40H-pgn tools http://40hchess.epizy.com/

## kisee bhee injan ke lie kushalataapoorvak adyatan karane yogy tantrika netavark (nnue) banaane ke nirdesh:
- ek upayukt vindoz vaataavaran sthaapit karana
  - [windows-environment.md](windows-environment.md)
- ka upayog karake ek kushal praarambhik pustak banaana cutechess-cli
  - [cutechess-opening-books.md](cutechess-opening-books.md)
- shoony enenayoo drshtikon ke lie selphaple gem chalaana
  - [engine-selfplay-via-cutechess-cli.md](engine-selfplay-via-cutechess-cli.md)
- peejeeen failon se fens aur deta praapt karane ke lie eeval-eksatraikt ka upayog karana
  - [nnue-extract_fen-&-data-extraction-&-conversion-to-plain-text.md](nnue-extract_fen-&-data-extraction-&-conversion-to-plain-text.md)
- saade paath deta failon ko nnuai .bin prashikshan praaroop mein parivartit karana
  - [plain-text-conversion-to-nnue-training-.bin-format.md](plain-text-conversion-to-nnue-training-.bin-format.md)
- prashikshan evan kamaand-lain prabandhan ka upayog karana nnue-gui
  - [create-a-nnue-with-nnue-gui.md](create-a-nnue-with-nnue-gui.md)
- utpann ka pareekshan nnues
  - [version-testing-with-little-blitzer.md](version-testing-with-little-blitzer.md)
- paryavekshit aur sudrdheekaran seekhane ke saath sudhaar karana
  - [improving-the-nnue.md](improving-the-nnue.md)

## monte-carlo khoj mod:  
![alt tag](https://raw.githubusercontent.com/FireFather/fire/master/docs/Fire_8.NN.MCx64.png)

phaayar-9 mein klaing, reeshaarpar see++ aur vijual stoodiyo kod enaalisis sahit aaj upalabdh kaee sabase aadhunik see++ tools ka upayog karake kaee maheenon tak saavadhaaneepoorvak vishleshan aur reephaiktaring kee gaee hai, jisase behad tej, uchch anukoolit aur sthir nishpaadan yogy ka utpaadan sunishchit hota hai.

## upalabdh Windows baayaneriz
- **x64 bmi2** = fast pgo binary (for modern 64-bit systems w/ BMI2 instruction set)yadi aapake paas intel haisavel ya naya seepeeyoo hai, to yah sankalan tez hona chaahie.
- **x64 avx2** = fast pgo binary (for modern 64-bit systems w/ AVX2 instruction set) yadi aapake paas aadhunik eemadee seepeeyoo hai, to yah sankalan sabase tez hona chaahie.
- **x64 popc** = fast pgo binary (for older 64-bit systems w/ SSE41 & POPCNT instruction sets) 

- **windows** : fire-9_x64_x64_bmi2.exe, fire-9_x64_avx2.exe, fire-9_x64_popc.exe

yah nirdhaarit karane ke lie ki aapake sistam par kaun sa bainaree sabase achchha/tez chalata hai, kamaand lain par bench chalaen. adhik sateekata ke lie, ise do baar chalaen aur donon parinaamon ke ausat kee ganana karen.

krpaya dekhen **http://chesslogik.wix.com/fire** adhik jaanakaaree ke lie

## ise svayan sankalit karen
- **windows** (visual studio) sammilit projekt failon ka upayog karen: Fire.vcxproj or Fire.sln
- **minGW** shaamil shel skript mein se ek chalaen: make_bmi2.sh, make_avx2.sh, make_popc.sh, or make_all.sh 
- **ubuntu** type 'make profile-build ARCH=x86-64-bmi2', 'make profile-build ARCH=x86-64-avx2', etc.

## uci vikalp
- **Hash** haih taalika ka aakaar. difolt hai 64 MB.
- **Threads** upayog karane ke lie prosesar threds kee sankhya. difolt 1 hai, adhikatam = 128.
- **MultiPV** aautaput ke lie peevee/pramukh vividhataon (khel kee panktiyaan) kee sankhya. difolt hai 1.
- **Contempt** uchchatar avamaanana ​​dro ka virodh karatee hai.
- **MoveOverhead** netavark aur jeeyooaee vilambata kee bharapaee ke lie ise samaayojit karen. samay par nukasaan se bachane ke lie yah upayogee hai.
- **MinimumTime** ek hee chaal par kharch karane ke lie poorn nyoonatam samay (emes mein). samay par hone vaale nukasaan se bachane ke lie bhee upayogee hai.
- **Ponder** virodhee ke samay bhee socho. difolt galat hai.
- **UCI_Chess960** shataranja960 khelen (aksar ephaarasee ya Fischer Random Shataranj kaha jaata hai). difolt galat hai.
- **Clear Hash** hash taalika saaf karen. aavantit memoree hataen aur punah aarambh karen.
- **SyzygyProbeDepth** injan nirdisht gaharaee par jaanch shuroo karata hai. is vikalp ko badhaane se injan jaanch kam ho jaatee hai.
- **EngineMode** NNUE(difolt), ya yaadrchchhik chunen.
- **MCTS** saksham monte kaarlo tree sarch w/ucht (pedon par laagoo ooparee konphidens baunds)
- **SyzygyProbeLimit** tebal-bes kee jaanch se pahale gem ke ant mein bord par hone vaale tukadon kee sankhya.
- **Syzygy50MoveRule** galat par set, 50-chaal niyam dvaara kheenchee gaee tebalabes sthiti ko jeet ya haar ke roop mein gina jaega.
- **SyzygyPath** syzygy tebalabes failon ka path.


![alt tag](https://raw.githubusercontent.com/FireFather/fire-zero/master/logos/fire_1.bmp)
![alt tag](https://raw.githubusercontent.com/FireFather/fire-zero/master/logos/fire_2.bmp)
![alt tag](https://raw.githubusercontent.com/FireFather/fire-zero/master/logos/fire_3.bmp)
![alt tag](https://raw.githubusercontent.com/FireFather/fire-zero/master/logos/fire_4.bmp)
![alt tag](https://raw.githubusercontent.com/FireFather/fire-zero/master/logos/fire_5.bmp)
![alt tag](https://raw.githubusercontent.com/FireFather/fire-zero/master/logos/fire_6.bmp)
![alt tag](https://raw.githubusercontent.com/FireFather/fire-zero/master/logos/fire_7.bmp)
![alt tag](https://raw.githubusercontent.com/FireFather/fire-zero/master/logos/fire_8.bmp)
![alt tag](https://raw.githubusercontent.com/FireFather/fire-zero/master/logos/fire_9.bmp)
![alt tag](https://raw.githubusercontent.com/FireFather/fire-zero/master/logos/fire_10.bmp)
![alt tag](https://raw.githubusercontent.com/FireFather/fire-zero/master/logos/fire_11.bmp)

## aabhaar

**hindee kod anuvaad par kaam karane ke lie dhanyavaad sanjeeb patel!**

phaayar mein shaamil kaee vichaaron aur takaneekon ko yahaan vistaar se pralekhit kiya gaya hai
- [Chess Programming Wiki](https://www.chessprogramming.org)

aur kuchh ko supar majaboot opan-sors shataranj injan se anukoolit kiya gaya hai
- [Stockfish](https://github.com/official-stockfish/Stockfish)

aur doosare
- [Ippolit](https://github.com/FireFather/ippolit)
- [Robbolito](https://github.com/FireFather/robbolito)
- [Firebird](https://github.com/FireFather/firebird)
- [Ivanhoe](https://www.chessprogramming.org/IvanHoe)
- [Houdini](https://www.cruxis.com/chess/houdini.htm)
- [Gull](https://github.com/FireFather/seagull)

endagem taalika aadhaaron ko anukoolit kod ka upayog karake kaaryaanvit kiya jaata hai Ronald de Man's
- [Syzygy EGTBs & probing code](https://github.com/syzygy1/tb)

enenayooee kaaryaanvayan ek sanshodhit sanskaran ka upayog karata haiDaniel Shawul's/Cfish utkrsht nnu jaanch kod
- [nnue-probe](https://github.com/dshawul/nnue-probe/)

mcts kaaryaanvayan se liya gaya hai Stephane Nicolet's kaam
- https://github.com/snicolet/Stockfish/commits/montecarlo

yadi aap meree vishesh altra-phaast pareekshan paddhati ke baare mein jaanane mein ruchi rakhate hain, to mainne ise yahaan kuchh vistaar se samajhaaya hai:
http://www.chessdom.com/fire-the-chess-engine-releases-a-new-version/

## laisens
ke antargat agni ka vitaran kiya jaata haiGNU General Public License. krpaya padhen LICENSE adhik jaanakaaree ke lie.

krpaya dekhen **http://chesslogik.wix.com/fire** adhik jaanakaaree ke lie

## kya aag stockfish kee tarah khelatee hai?
nahin, yahaan parinaam hain Don Daily's SIM kaaryakram (difolt maan) ko maapane ke lie aaj Fire 8.NN chayan banaam pichhale 4 sanskaranon ko sthaanaantarit karen Stockfish:

![alt tag](https://raw.githubusercontent.com/FireFather/fire/master/docs/matrix.png)

Aaap dekh sakate hain ki stockfish 14.1 aur stockfish 15 ~64% samay mein samaan chaal chalate hain (dekhana pankti 4, kolam 5)

Fire 8.NN ka utkrsht skor ~43.34% hai (pankti 1 dekhen), jo lagabhag 60% samay mein eseph se bhinn chaalen banaata hai.

sim tool yahaan se daunalod kiya ja sakata hai:
https://komodochess.com/downloads.htm

yadi aap samaanata pareekshan parinaamon mein ruchi rakhate hain, to yah bhee dekhen:
https://github.com/FireFather/sim03


saabhaar-

firefather@telenet.be
