#pragma once
#include "Exercise00_NowcoderTools.h"
/*�������è��������:
class Pet {
	string type;

public:
	Pet(string type) {
		this.type = type;
	}
	
	string getPetType() {
		return this.type;
	}
}

class Dog: public Pet {
public:
	Dog() {
		super("dog");
	}
}

class Cat: public Pet {
public:
	Cat() {
		super("cat");
	}
}

ʵ��һ�ֹ�è���еĽṹ��Ҫ������:
�û����Ե���add������cat���dog��� ʵ�����������;
�û����Ե���pollAll�����������������е�ʵ�����ս����� ���Ⱥ�˳�����ε���;
�û����Ե���pollDog��������������dog���ʵ������ �����е��Ⱥ�˳�����ε���;
�û����Ե���pollCat��������������cat���ʵ �����ս����е��Ⱥ�˳�����ε���;
�û����Ե���isEmpty���������������� ����dog��cat��ʵ��;
�û����Ե���isDogEmpty���������������Ƿ���dog ���ʵ��;
�û����Ե���isCatEmpty���������������Ƿ���cat���ʵ����
Ҫ���������з���ʱ�临�Ӷȶ���O(1)*/