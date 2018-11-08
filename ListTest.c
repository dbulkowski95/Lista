#include "list.h"
#include <criterion.h>
#include <limits.h>
#include <stdio.h>


/*CLEAR() na poczatku uzyty w celu usuniecia przeciekow w valgrindzie*/
Test(InitTest, init_check)
{
	listS *listTester = init();
	cr_expect_not_null(listTester, "Correct allocation");
	clear(&listTester);
}

Test(InitTest, init_false)
{
	listS *listTester = init();
	cr_expect(listTester == NULL, "Expect false");
	clear(&listTester);
}

Test(InitTest, init_head_true)
{
	listS *listTester = init();
	cr_expect(listTester->head == NULL, "Expect true");
	clear(&listTester);
}

Test(InitTest, init_head_false)
{
	listS *listTester = init();
	cr_expect(listTester->head != NULL, "Expect false");
	clear(&listTester);
}

Test(ClearTest, clear_after_init_list_true)
{
	listS *listTester = init();
	clear(&listTester);
	cr_expect(listTester == NULL, "Expect true");
}

Test(push_back_test, one_push_true)
{
	listS *listTester = init();
	push_back(listTester, 0);
	cr_expect(listTester->head != NULL, "Expect true");
	clear(&listTester);
	cr_expect(listTester == NULL, "Expect true");
}

Test(push_back_test, one_few_true)
{
	listS *listTester = init();
	for (int i = 0; i <1000; i++)
	{
		push_back(listTester, i);
	}
	cr_expect(listTester->head != NULL, "Expect true");
	clear(&listTester);
	cr_expect(listTester == NULL, "Expect true");
}

Test(push_back_test, Uninitalized_list)
{
	listS *listTester = NULL;
	cr_expect(push_back(listTester,0) == -1, "Expect true");
	listTester = init();
	cr_expect(push_back(listTester,1) == 0, "Expect true");
	clear(&listTester);
}

Test(push_back_test, bad_second_arg_in_function)
{
	listS *listTester = init();
	cr_expect(push_back(listTester,INT_MAX +1) == 0, "Expect true");
	cr_expect(push_back(listTester,INT_MAX) == 0, "Expect true");
	cr_expect(push_back(listTester,(-1)*INT_MAX) == 0, "Expect true");
	cr_expect(push_back(listTester,'c') == 0, "Expect true");
	cr_expect(push_back(listTester,"asfb") == 0, "Expect true");
	clear(&listTester);
}

Test(popback_tests, pop_uninit_list)
{
	listS *listTester = NULL;
	int returnValue = 0;
	cr_expect(pop_back(listTester,&returnValue) == -1, "Expect pop equal -1");
	listTester = init();
	for (int i = 0; i <1000; i++)
	{
		cr_expect(push_back(listTester, i) == 0);
	}
	cr_expect(pop_back(listTester,&returnValue) == 0, "Expect pop equal 0");
	cr_expect_geq(returnValue, 0, "Expect value greater or equal 0");
	clear(&listTester);
}

Test(popback_tests, push_and_pop)
{
	listS *listTester = init();
	int returnValue = 0;
	push_back(listTester, 1);
	pop_back(listTester,&returnValue);
	cr_expect_null(listTester->head, "Expect head equal null");
	clear(&listTester);
}

Test(popfront_tests, pop_uninit_list)
{
	listS *listTester = NULL;
	int returnValue = 0;
	cr_expect(pop_front(listTester,&returnValue) == -1, "Expect pop equal -1");
	listTester = init();
	cr_expect(listTester->head == NULL, "Expect true");
	cr_expect(pop_front(listTester,&returnValue) == 0, "Expect pop equal 0");
	for (int i = 0; i <1000; i++)
	{
		cr_expect(push_back(listTester, i) == 0);
	}
	cr_expect(pop_front(listTester,&returnValue) == 0, "Expect pop equal 0");
	cr_expect_geq(returnValue, 0, "Expect value greater or equal 0");
	clear(&listTester);
}

Test(popfront_tests, push_and_pop)
{
	listS *listTester = init();
	int returnValue = 0;
	push_back(listTester, 1);
	pop_front(listTester,&returnValue);
	cr_expect_null(listTester->head, "Expect head equal null");
	cr_expect_geq(returnValue, 0, "Expect value greater or equal 0");
	clear(&listTester);
}
