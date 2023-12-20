#include <iostream>
#include "TStack.h"
#pragma once

int Prior(char c)
{
  if (c == '*' || c == '/')
    return 3;
  else if (c == '+' || c == '-')
    return 2;
  else if (c == '(')
    return 1;
  else
    throw "Invalid operator";
}


char* Stroka(char* s)
{
  TStack<char> l;
  int count = strlen(s);
  char* s2 = new char[count];
  int g = 0, i = 0;
  while (i < count)
  {
    if (isdigit(s[i]))
    {
      s2[g] = s[i];
      g++;
    }
    else if (s[i] == ')')
    {
      char m = l.Pull();
      while (m != '(')
      {
        s2[g] = m;
        g++;
      }
    }
    else
    {
      int p = Prior(s[i]);
      if (l.IsEmpty())
      {
        l.Push(s[i]);
      }
      else
      {
        char m = l.Pull();
        int pm = Prior(m);
        if (pm < p)
        {
          l.Push(m);
          l.Push(s[i]);
        }
        else
        {
          while ((pm > p) && (!(l.IsEmpty())))
          {
            s2[g] = m;
            g++;
            m = l.Pull();
            pm = Prior(m);
          }
          l.Push(m);
          l.Push(s[i]);
        }
      }
    }
    i++;
  }
  return s2;
}

double Calc(char* s)
{
  TStack<double> number;
  TStack<char> operate;
  for (int i = 0; i < strlen(s); i++)
  {
    char curr = s[i];
    if (isdigit(curr))
      number.Push(curr - '0');
    else if (curr == '+' || curr == '-' || curr == '*' || curr == '/')
      operate.Push(curr);
    else if (curr == '=')
    {
      while (!(operate.IsEmpty()))
      {
        char operation = operate.Top();
        operate.Pull();
        double num2 = number.Top();
        number.Pull();
        double num1 = number.Top();
        number.Pull();

        if (operation == '+')
          number.Push(num1 + num2);
        else if (operation == '-')
          number.Push(num1 - num2);
        else if (operation == '*')
          number.Push(num1 * num2);
        else if (operation == '/')
          number.Push(num1 / num2);
      }
    }
  }
  return number.Top();
}
