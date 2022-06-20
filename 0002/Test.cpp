#include <Start.h>

#include "ListNode.h"
#include "Solution.h"

typedef int TestCase; // DUMMY
#include <SolFixture.h>

ListNode *MakeListNode(std::initializer_list<int> init) {
  ListNode *ret = new ListNode();
  ListNode *cur = ret;

  for (auto it = init.begin(); it != init.end(); ++it) {
    cur->val = *it;

    if (std::next(it) != init.end()) {
      cur->next = new ListNode();
      cur = cur->next;
    }
  }

  return ret;
}

bool Verify(ListNode *out, ListNode *res) {
  while (out && res) {
    if (out->val != res->val)
      return false;

    out = out->next;
    res = res->next;
  }

  if (out != nullptr && res != nullptr)
    return false;

  return true;
}

TEST_F(SolFixture, TestCase_1) {
  ListNode *l1 = MakeListNode({2, 4, 3});
  ListNode *l2 = MakeListNode({5, 6, 4});
  ListNode *out = MakeListNode({7, 0, 8});

  ListNode *res = sol.addTwoNumbers(l1, l2);

  if (!Verify(out, res))
    FAIL();
  SUCCEED();
}

TEST_F(SolFixture, TestCase_2) {
  ListNode *l1 = MakeListNode({0});
  ListNode *l2 = MakeListNode({0});
  ListNode *out = MakeListNode({0});

  ListNode *res = sol.addTwoNumbers(l1, l2);

  if (!Verify(out, res))
    FAIL();
  SUCCEED();
}

TEST_F(SolFixture, TestCase_3) {
  ListNode *l1 = MakeListNode({9, 9, 9, 9, 9, 9, 9});
  ListNode *l2 = MakeListNode({9, 9, 9, 9});
  ListNode *out = MakeListNode({8, 9, 9, 9, 0, 0, 0, 1});

  ListNode *res = sol.addTwoNumbers(l1, l2);

  if (!Verify(out, res))
    FAIL();
  SUCCEED();
}