#pragma once
#include "Exercise00_NowcoderTools.h"
/*һ���Ϸ�������ƥ�����������¶���:
�ٿմ�""��һ���Ϸ�������ƥ������
�����"X"��"Y"���ǺϷ�������ƥ������,"XY"Ҳ��һ���Ϸ�������ƥ������
�����"X"��һ���Ϸ�������ƥ������,��ô"(X)"Ҳ��һ���Ϸ�������ƥ������
��ÿ���Ϸ����������ж����������Ϲ������ɡ�
����: "","()","()()","((()))"���ǺϷ�����������
����һ���Ϸ����������������������¶����������:
�ٿմ�""�������0
������ַ���"X"�������x,�ַ���"Y"�������y,��ô�ַ���"XY"�����Ϊ
max(x,y) 3�����"X"�������x,��ô�ַ���"(X)"�������x+1
����: "()()()"�������1,"((()))"�������3��ţţ���ڸ���һ���Ϸ�������
����,��Ҫ����������ȡ�*/