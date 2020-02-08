/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	int carry = 0;
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
	{
		ListNode* l1Prev=NULL,* l2Prev=NULL,* l3 = NULL;
		if (l1 != NULL && l2 != NULL)
		{
			l3 = func(l1,l2);
			std::cout << "first val" << l3->val << std::endl;
			l1Prev = l1;
			l2Prev = l2;
		}
		else if (l1 !=NULL&&l2==NULL)
		{
			return l1;
		}
		else if (l1 ==NULL&&l2!=NULL)
		{
			return l2;
		}
		else if (l1 == NULL && l2 == NULL)
		{
			return NULL;
		}
		int temp = Loop(l1Prev, l2Prev, l3);
		std::cout << temp << std::endl;
		return l3;
	}
	int Loop(ListNode* l1Prev,ListNode* l2Prev,ListNode* l3Prev)
	{
		if (l1Prev == NULL && l2Prev == NULL)
		{
			if (carry != 0)
			{
				l3Prev->next = func();
				l3Prev = l3Prev->next;
				return 0;
			}
			else if(carry == 0)
			{
				return -1;
			}
		}
		else if (l1Prev == NULL && l2Prev != NULL)
		{
			l3Prev->next = func(l2Prev->next);
			l2Prev = l2Prev->next;
			l3Prev = l3Prev->next;
		}
		else if((l1Prev != NULL)&&(l2Prev == NULL))
		{
			l3Prev->next = func(l1Prev->next);
			 l1Prev = l1Prev->next;
			 l3Prev = l3Prev->next;
		}
		else if ((l1Prev != NULL) && (l2Prev != NULL))
		{
			l3Prev->next = func(l1Prev->next, l2Prev->next);
			l1Prev = l1Prev->next;
			l2Prev = l2Prev->next;
			l3Prev = l3Prev->next;
		}
		//std::cout << l3Prev->val << std::endl;
		Loop(l1Prev, l2Prev,l3Prev);
		return 1;
	}
	ListNode* func(ListNode* l1 = NULL, ListNode* l2 = NULL)
	{
		if (l1!=NULL&&l2!=NULL) 
		{
			if (l1->val + l2->val + carry > 9)
			{
				int temp = (l1->val + l2->val + carry) % 10;
				carry = (l1->val + l2->val + carry) / 10;
				std::cout << "FUNC::FF WITH >10 AND TEMP IS" << temp << " AND CARRY IS"<<carry<< std::endl;
				return new ListNode(temp);
			}
			else
			{
				int temp = (l1->val + l2->val + carry) % 10;
				carry = 0;
				std::cout << "FUNC::FF WITH <10 AND TEMP IS" << temp << " AND CARRY IS" << carry << std::endl;
				return new ListNode(temp);
			}
		}
		else if (l1 != NULL && l2 == NULL)
		{
			if (l1->val + carry > 9)
			{
				int temp = (l1->val + carry) % 10;
				carry = (l1->val + carry) / 10;
				std::cout << "FUNC::FT WITH >10 AND TEMP IS" << temp << " AND CARRY IS" << carry << std::endl;
				return new ListNode(temp);
			}
			else
			{
				int temp = (l1->val + carry) % 10;
				carry = 0;
				std::cout << "FUNC::FT WITH <10 AND TEMP IS" << temp << " AND CARRY IS" << carry << std::endl;
				return new ListNode(temp);
			}
		}
		else if (l1 == NULL && l2 != NULL)
		{
			if (l2->val + carry > 9)
			{
				int temp = (l2->val + carry) % 10;
				carry = (l2->val + carry) / 10;
				std::cout << "FUNC::FT WITH >10 AND TEMP IS" << temp << " AND CARRY IS" << carry << std::endl;
				return new ListNode(temp);
			}
			else
			{
				int temp = (l2->val + carry) % 10;
				carry = 0;
				std::cout << "FUNC::FT WITH <10 AND TEMP IS" << temp << " AND CARRY IS" << carry << std::endl;
				return new ListNode(temp);
			}
		}
		else if(l1==NULL&&l2==NULL)
		{
			if (carry > 9)
			{
				int temp = (carry) % 10;
				carry = (carry) / 10;
				std::cout << "FUNC::TT WITH >10 AND TEMP IS" << temp << " AND CARRY IS" << carry << std::endl;
				return new ListNode(temp);
			}
			else if (carry != 0)
			{
				int temp = (carry) % 10;
				carry = 0;
				std::cout << "FUNC::TT WITH !=10 AND TEMP IS" << temp << " AND CARRY IS" << carry << std::endl;
				return new ListNode(temp);
			}
			else if (carry == 0)
			{
				return NULL;
			}
			
		}
		return NULL;

	}
};