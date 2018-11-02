#include "list.h"
#include <criterion.h>
#include <stdio.h>


Test(InitAndClear, init)
{
	list *list_p = init();
	pop_back(list_p);
	push_back(list_p,1);
	push_back(list_p,2);
	push_back(list_p,3);
	pop_back(list_p);
	pop_front(list_p);
	clear(list_p);
	pop_front(list_p);
	pop_back(list_p);
	free(list_p);
}

Test(InitAddClear, init)
{
	list *list_p = init();
	push_back(list_p,1);
	clear(list_p);
	free(list_p);
}


Test(simpleTestSuite, pushLotOfNumbers)
{
	static int counter = 0;
	list *list_p = init();
	for(size_t i = 0;i<1000;i++){
		push_back(list_p,i);
		counter++;
	}
	for(size_t i = 0;i<500;i++){
		pop_back(list_p);
		counter--;
	}
	clear(list_p);
	printf("->%d\n", counter);
	free(list_p);
}

Test(simpleTestSuite, PrintBeforePush1)
{
	list *list_p = init();
	print(list_p);
	for(size_t i = 0;i<10;i++){
		push_back(list_p,i);
	}
	print(list_p);
	clear(list_p);
	print(list_p);
	free(list_p);
}


	Test(simpleTestSuite, PrintBeforePush)
	{
		list *list_p = init();
		print(list_p);
		clear(list_p);
		print(list_p);

		for(size_t i = 0;i<1;i++){
			printf("add\n");
			push_back(list_p,i);
		}
		print(list_p);
		clear(list_p);
		print(list_p);

		for(size_t i = 0;i<2;i++){
			push_back(list_p,i);
		}
		print(list_p);
		clear(list_p);
		print(list_p);

		for(size_t i = 0;i<3;i++){
			push_back(list_p,i);
		}
		print(list_p);
		clear(list_p);
		print(list_p);

		for(size_t i = 0;i<300;i++){
			push_back(list_p,i);
		}
		print(list_p);
		clear(list_p);
		print(list_p);

		free(list_p);
	}

	Test(clear_tests, ClearWithLotpush_backs)
	{
	    list* HEAD = init();

	   push_back(HEAD,3);
	   push_back(HEAD,3);
	   push_back(HEAD,3);
	   push_back(HEAD,3);
	   clear(HEAD);
	   cr_assert_null(HEAD->head,"Lista po uzyciu funkcji clear nie jest zakonczona NULLem");
	   free(HEAD);
	}

	Test(print_tests, PrintAfterInit)
	{
	    list* HEAD = init();
	    int i = print(HEAD);
	    cr_expect(i,"Blad funkcji print dla braku NODE'ow");
	    free(HEAD);
	}

	Test(clear_tests, OnlyInitAndClear)
	{
	    list* HEAD = init();
	    clear(HEAD);
	    cr_assert_null(HEAD->head,"Zainicjalizowana lista po użyciu clear() nie jest zakończona NULLem");
	    free(HEAD);
	}

	Test(pop_tests, PopFirstNode)
	{
	    list* HEAD = init();
	    int rand_val = 3;
	    push_back(HEAD,rand_val);
	    pop_front(HEAD);
	    cr_assert_null(HEAD->head,"HEAD nie wskazuje na NULL po użyciu pop() na jednoelementowej liście");
	    free(HEAD);
	}

	Test(pop_tests, PopMultipleNode)
	{
	    list* HEAD = init();
	    int rand_val = 3;
	    for(int i=0; i<6; i++)
	    {
	        push_back(HEAD,i*rand_val);
	    }
	    pop_front(HEAD);
	    pop_front(HEAD);
	    cr_assert_not_null(HEAD->head,"HEAD wskazuje na NULL po użyciu pop() na wieloelementowej liście (a nie powinien)");
	    clear(HEAD);
	    free(HEAD);
	}
