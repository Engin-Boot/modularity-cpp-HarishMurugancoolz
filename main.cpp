#include <iostream>
#include <assert.h>
#include <string>
#include "TelCoColorCoder.h"
using namespace TelCoColorCoder;
using namespace std;
void testNumberToPair(int pairNumber,
    TelCoColorCoder::MajorColor expectedMajor,
    TelCoColorCoder::MinorColor expectedMinor)
{
    TelCoColorCoder::ColorPair colorPair =
        TelCoColorCoder::GetColorFromPairNumber(pairNumber);
    std::cout << "Got pair " << colorPair.ToString() << std::endl;
    assert(colorPair.getMajor() == expectedMajor);
    assert(colorPair.getMinor() == expectedMinor);
}

void testPairToNumber(
    TelCoColorCoder::MajorColor major,
    TelCoColorCoder::MinorColor minor,
    int expectedPairNumber)
{
    int pairNumber = TelCoColorCoder::GetPairNumberFromColor(major, minor);
    std::cout << "Got pair number " << pairNumber << std::endl;
    assert(pairNumber == expectedPairNumber);
}
string referenceManual()
{
    string manual = "Reference Manual \n";
    for(int i_pairNumber=1;i_pairNumber<=numberOfMajorColors*numberOfMinorColors;i_pairNumber++)
    {
        TelCoColorCoder::ColorPair colorPair=TelCoColorCoder::GetColorFromPairNumber(i_pairNumber);
        manual+=to_string(i_pairNumber);
        manual+=" ";
        manual+=colorPair.ToString();
        manual+="\n";
    }
    return manual;
}

int main() {
    testNumberToPair(4, TelCoColorCoder::WHITE, TelCoColorCoder::BROWN);
    testNumberToPair(5, TelCoColorCoder::WHITE, TelCoColorCoder::SLATE);
    testPairToNumber(TelCoColorCoder::BLACK, TelCoColorCoder::ORANGE, 12);
    testPairToNumber(TelCoColorCoder::VIOLET, TelCoColorCoder::SLATE, 25);
    cout<<referenceManual();
    return 0;
}
