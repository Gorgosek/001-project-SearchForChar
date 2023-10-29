#!/bin/bash
#
# Tests for 1. IZP project [2023]
# Author: _ramb0_
# Usage:
#     ./test_keyfilter.sh


# Color codes
RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m' # No Color

# Compile the program
gcc -std=c11 -Wall -Wextra -Werror keyfilter2.c -o keyfilter

run_test() {
	input_file=$1
	test_arg=$2
	expected_output=$3

	echo -n "Running test with input from $input_file and argument ${test_arg:0:10}... "

		actual_output=$(./keyfilter $test_arg < $input_file)

		if [[ "$actual_output" == "$expected_output" ]]; then
			echo -e "${GREEN}PASSED${NC}"
		else
			echo -e "${RED}FAILED${NC}"
			echo "Expected: $expected_output"
			echo "Got:      $actual_output"
		fi
	}

# Test cases
echo -e "Praha\nBrno\nBruntal\nBratislava" > test_01.txt

run_test "test_01.txt" "" "Enable: BP"

run_test "test_01.txt" "b" "Enable: R"
run_test "test_01.txt" "B" "Enable: R"

run_test "test_01.txt" "br" "Enable: ANU"
run_test "test_01.txt" "BR" "Enable: ANU"

run_test "test_01.txt" "brn" "Found: BRNO"
run_test "test_01.txt" "BRN" "Found: BRNO"

run_test "test_01.txt" "be" "Not found"
run_test "test_01.txt" "BE" "Not found"

# More complex file
echo -e "Praha\nBrno\nBruntal\nBratislava\nBerlin\nBudapest\nPrague\nBrunswick\nBritain\nBrazil\nBremen" > test_02.txt

run_test "test_02.txt" "" "Enable: BP"

run_test "test_02.txt" "b" "Enable: ERU"

run_test "test_02.txt" "br" "Enable: AEINU"
run_test "test_02.txt" "BR" "Enable: AEINU"

run_test "test_02.txt" "bru" "Enable: N"
run_test "test_02.txt" "BRU" "Enable: N"

run_test "test_02.txt" "brun" "Enable: ST"

run_test "test_02.txt" "brunt" "Found: BRUNTAL"

run_test "test_02.txt" "be" "Found: BERLIN"

run_test "test_02.txt" "ber" "Found: BERLIN"

run_test "test_02.txt" "berl" "Found: BERLIN"

run_test "test_02.txt" "bremen" "Found: BREMEN"

run_test "test_02.txt" "p" "Enable: R"

echo -e "TohleJeTestNaStoCharakteruDlouhejRadekJestliNahodouJsiTamNeudelalChybickuFrajereJustAskingYouKnowHeh" > test_03.txt

run_test "test_03.txt" "to" "Found: TOHLEJETESTNASTOCHARAKTERUDLOUHEJRADEKJESTLINAHODOUJSITAMNEUDELALCHYBICKUFRAJEREJUSTASKINGYOUKNOWHEH"

# Test special characters
echo -e " \n1\n2\n3\n!\n:\n_\n;\n~\nA\nB\nc" > test_04.txt

run_test "test_04.txt" "" "Enable:  !123:;ABC_~"

echo -e "Praha\nBrno\nBruntal\nBratislava\nBerlin\nBudapest\nPrague\nBrunswick\nBritain\nBrazil\nBremen\nOslo\nZurich\nHelsinki\nHamburg\nHannover\nMumbai\nDelhi\nChennai\nMadrid\nRome\nWarsaw\nParis\nVienna\nCopenhagen\nStockholm\nDublin\nEdinburgh\nLondon\nManchester\nLiverpool\nGlasgow\nLeeds\nBirmingham\nMilan\nBarcelona\nValencia\nSeville\nVancouver\nToronto\nMontreal\nCalgary\nOttawa\nQuebec\nTokyo\nOsaka\nKyoto\nSapporo\nNagasaki\nHiroshima\nBeijing\nShanghai\nShenzhen\nGuangzhou\nChengdu\nHangzhou\nWuhan\nTaipei\nSeoul\nBusan\nDaegu\nJeju\nUlaanbaatar\nBangkok\nPhuket\nChiang Mai\nPattaya\nManila\nCebu\nBoracay\nJakarta\nBali\nSurabaya\nBandung\nKuala Lumpur\nPenang\nLangkawi\nSingapore\nHo Chi Minh City\nHanoi\nDanang\nPhnom Penh\nSiem Reap\nVientiane\nYangon\nNaypyidaw\nDhaka\nKolkata\nIslamabad\nKarachi\nLahore\nTashkent\nAstana\nAlmaty" > test_08.txt

run_test "test_08.txt" "B" "Enable: AEIORU"

echo -e "Miami\nAustin\nDallas\nHouston\nDenver\nDetroit\nBoston\nSeattle\nPortland\nSan Francisco\nSan Diego\nSan Antonio\nSacramento\nPittsburgh\nPhiladelphia\nOrlando\nOklahoma City\nOakland\nNew York City\nNew Orleans\nNashville\nMinneapolis\nMilwaukee\nMemphis\nLos Angeles\nLas Vegas\nKansas City\nJacksonville\nIndianapolis\nFort Worth\nEl Paso\nColumbus\nCleveland\nChicago\nCharlotte\nBaltimore\nAtlanta\nAnchorage\nAlbuquerque\nPhoenix\nTucson\nSalt Lake City\nRaleigh\nProvidence\nNewark\nBuffalo\nBaton Rouge\nArlington\nAnaheim\nCincinnati\nOmaha\nLouisville\nRichmond\nPeoria\nPalm Springs\nNorfolk\nSt. Louis\nReno\nRapid City\nTampa\nTacoma\nSyracuse\nSpringfield\nSpokane\nShreveport\nSanta Ana\nSalem\nSacramento\nRochester\nRiverside\nPomona\nPasadena\nOxnard\nOceanside\nOakland\nNiagara Falls\nNewport News\nNashua\nMobile\nMesa\nMedford\nMacon\nLubbock\nLittle Rock\nLexington\nLansing\nLakewood\nKnoxville\nJackson\nIrvine\nHuntsville" > test_010.txt

run_test "test_010.txt" "Sa" "Enable: CLN"

echo -e "Canberra\nSydney\nMelbourne\nPerth\nBrisbane\nAdelaide\nGold Coast\nHobart\nCairns\nGeelong\nNewcastle\nToowoomba\nBallarat\nBendigo\nDarwin\nLaunceston\nMackay\nRockhampton\nBunbury\nWollongong\nAlbury\nBathurst\nBlue Mountains\nBroken Hill\nCampbelltown\nCessnock\nDubbo\nGoulburn\nGrafton\nLithgow\nLiverpool\nOrange\nParramatta\nPenrith\nQueanbeyan\nTamworth\nWagga Wagga\nWindsor\nAbbotsford\nArmstrong\nBurnaby\nChilliwack\nCoquitlam\nDuncan\nEnderby\nFernie\nFort St. John\nGrand Forks\nGreenwood\nKamloops\nKelowna\nKimberley\nLangley\nNanaimo\nNelson\nNew Westminster\nNorth Vancouver\nParksville\nPenticton\nPitt Meadows\nPort Alberni\nPort Coquitlam\nPort Moody\nPrince George\nPrince Rupert\nQuesnel\nRevelstoke\nRichmond\nRossland\nSalmon Arm\nSurrey\nTerrace\nVancouver\nVernon\nVictoria\nWhite Rock\nWilliams Lake\nKitchener\nLondon\nNiagara Falls\nNorfolk County\nNorth Bay\nOrillia\nOshawa\nOttawa\nOwen Sound\nPembroke\nPeterborough\nPickering\nPort Colborne\nPrince Edward County\nQuinte West\nSarnia" > test_011.txt

run_test "test_011.txt" "Pe" "Enable: MNRT"

rm test_011.txt
rm test_010.txt
rm test_08.txt
rm test_04.txt
rm test_03.txt
rm test_02.txt
rm test_01.txt
