#include "gmock/gmock.h"

int main() {
	::testing::InitGoogleMock();
	RUN_ALL_TESTS();

	return 0;
}