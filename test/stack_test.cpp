#include "pch.h"

namespace STACK_T {
	class STK : public testing::Test {
	public:
		Stack* list = new Stack;
		void SetUp() {
			// pass
		}
		void TearDown() {
			delete list;
		}
	};
}