#!/usr/bin/env python
import sys


def is_operator(char):
    ret = False
    if char == '*' or char == '+' or char == '/' or char == '-' or char == '^':
        ret = True
    return ret


def get_precedence(char):
    ret = None
    if char == '^':
        ret = 3
    if char == '*' or char == '/':
        ret = 2
    if char == '+' or char == '-':
        ret = 1
    return ret


def postfix(expr):
    # initializations
    stack = []
    postfix_expr = ""
    stack.append('(')
    expr += ')'
    # http://en.wikipedia.org/wiki/Reverse_Polish_notation#Postfix_algorithm
    for c in expr:
        if len(stack) == 0:
            break
        if not is_operator(c) and c != ')' and c != '(':
            postfix_expr = postfix_expr + c
        if c == '(':
            stack.append('(')
        if is_operator(c):
            while is_operator(stack[-1]) and get_precedence(stack[-1]) >= c:
                postfix_expr = postfix_expr + stack.pop()
            stack.append(c)
        if c == ')':
            while stack[-1] != '(':
                postfix_expr = postfix_expr + stack.pop()
            stack.pop()
    return postfix_expr

if __name__ == '__main__':
    cases = int(sys.stdin.readline())
    for i in range(0, cases):
        ex = sys.stdin.readline()
        print postfix(ex).strip()






