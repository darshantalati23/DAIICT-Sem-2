/**
 * Problem Statement

    You are designing a system for managing an Emergency Room (ER) where patients arrive with different levels of severity.

    Each patient has a name and a severity level (1 to 5, where 5 is the most severe).

    The ER follows a priority-based treatment system:
    Patients with higher severity (larger numbers) get treated first.
    If two patients have the same severity, the one who arrived earlier gets treated first (FIFO).
    Implement an ER system that supports the following operations:
    ARRIVE name severity → A new patient arrives.
    TREAT → The most severe patient is treated and removed.
    NEXT → Display the next patient to be treated.
    EXIT → End the simulation.
    Each command is given on a separate line.
    The input ends with the command EXIT.
    For TREAT, print "Treating <name>".
    For NEXT, print "Next patient: <name>".
    If no patients are in the ER and TREAT or NEXT is called, print "No patients in the ER".
    1 ≤ name length ≤ 20
    1 ≤ severity ≤ 5
    Maximum 1000 operations
    Example Input & Output:

    Input:
    ARRIVE Alice 3
    ARRIVE Bob 5
    ARRIVE Charlie 4
    NEXT
    TREAT
    NEXT
    TREAT
    NEXT
    TREAT
    NEXT
    EXIT

    Output:
    Next patient: Bob
    Treating Bob
    Next patient: Charlie
    Treating Charlie
    Next patient: Alice
    Treating Alice
    No patients in the ER

 */

#include <bits/stdc++.h>
using namespace std;

struct node
{
   string name;
   int sl;
   node *next;
};

node *head = nullptr;
node *rear = nullptr;

void arrive(string name, int severity)
{
   node *newNode = new node{name, severity, nullptr};

   // Empty list case
   if (head == nullptr)
   {
      head = rear = newNode;
      return;
   }

   node *cur = head;
   node *pre = nullptr;
   while (cur != nullptr && cur->sl >= severity)
   {
      pre = cur;
      cur = cur->next;
   }

   if (pre == nullptr)
   {
      newNode->next = head;
      head = newNode;
   }
   else
   {
      pre->next = newNode;
      newNode->next = cur;
      if (cur == nullptr)
         rear = newNode;
   }
}

void treat()
{
   if (head == nullptr)
   {
      cout << "No patients in the ER" << endl;
      return;
   }
   cout << "Treating " << head->name<<endl;
   if (head == rear)
   {
      head = nullptr;
      rear = nullptr;
   }
   else
   {
      node *temp = head;
      head = head->next;
      delete (temp);
   }
}

void next()
{
   if (head == nullptr)
   {
      cout << "No patients in the ER" << endl;
      return;
   }
   cout << "Next patient " << head->name<<endl;
}

int main()
{
   string s = "Hi";
   while (true)
   {
      cin >> s;
      if (s == "ARRIVE")
      {
         string nm;
         int sl;
         cin >> nm >> sl;
         arrive(nm, sl);
      }
      else if (s == "TREAT")
      {
         treat();
      }
      else if (s == "NEXT")
      {
         next();
      }
      else
      {
         return 0;
      }
   }
}