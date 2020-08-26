#include <iostream>
#include <assert.h>
#include "TelCoColorCoder.h"
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
void referenceManual()
{
    std::cout<<"Reference Manual"<<std::endl;
    for(int i_pairNumber=1;i_pairNumber<=TelCoColorCoder::numberOfMajorColors*TelCoColorCoder::numberOfMinorColors;i_pairNumber++)
    {
        TelCoColorCoder::ColorPair colorPair=TelCoColorCoder::GetColorFromPairNumber(i_pairNumber);
        std::cout<<i_pairNumber<<" "<<colorPair.ToString()<<std::endl;
    }
}

int main() {
    testNumberToPair(4, TelCoColorCoder::WHITE, TelCoColorCoder::BROWN);
    testNumberToPair(5, TelCoColorCoder::WHITE, TelCoColorCoder::SLATE);
    testPairToNumber(TelCoColorCoder::BLACK, TelCoColorCoder::ORANGE, 12);
    testPairToNumber(TelCoColorCoder::VIOLET, TelCoColorCoder::SLATE, 25);
    referenceManual();
    return 0;
}
