/*复制含有随机指针节点的链表
【题目】一种特殊的单链表节点类描述如下
class Node {
int value;
Node next;
Node rand;
Node(int val) {
value = val;
}
}
rand指针是单链表节点结构中新增的指针，rand可能指向链表中的任意一个节
点，也可能指向null。给定一个由Node节点类型组成的无环单链表的头节点
head，请实现一个函数完成这个链表的复制，并返回复制的新链表的头节点。
【要求】时间复杂度O(N)，额外空间复杂度O(1)*/