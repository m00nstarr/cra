#include <iostream>
#include "gtest/gtest.h"
int main() {
    //for (int i = 0; i < 33; i++) {
    //    Tennis tennisGame;
    //    string result = tennisGame.getCurrentScore(arr[i].score1, arr[i].score2);
    //    if (result == arr[i].result) {
    //        std::cout << "P";
    //    }
    //    else {
    //        std::cout << '\n';
    //        std::cout << "FAIL : " << i << "/33 테스트에서 Fail 발생\n";
    //        std::cout << "result가" << arr[i].result << "이 아니라 "
    //            << result << "입니다" << std::endl;
    //        break;
    //    }
    //}
    
    testing::InitGoogleTest();
    RUN_ALL_TESTS();

    return 0;
}