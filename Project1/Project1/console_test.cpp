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
    //        std::cout << "FAIL : " << i << "/33 �׽�Ʈ���� Fail �߻�\n";
    //        std::cout << "result��" << arr[i].result << "�� �ƴ϶� "
    //            << result << "�Դϴ�" << std::endl;
    //        break;
    //    }
    //}
    
    testing::InitGoogleTest();
    RUN_ALL_TESTS();

    return 0;
}