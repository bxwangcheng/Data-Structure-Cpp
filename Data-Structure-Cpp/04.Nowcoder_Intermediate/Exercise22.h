#pragma once
#include "Exercise00_NowcoderTools.h"
/*�������è��������:


ʵ��һ�ֹ�è���еĽṹ��Ҫ������:
�û����Ե���add������cat���dog��� ʵ�����������;
�û����Ե���pollAll�����������������е�ʵ�����ս����� ���Ⱥ�˳�����ε���;
�û����Ե���pollDog��������������dog���ʵ������ �����е��Ⱥ�˳�����ε���;
�û����Ե���pollCat��������������cat���ʵ �����ս����е��Ⱥ�˳�����ε���;
�û����Ե���isEmpty���������������� ����dog��cat��ʵ��;
�û����Ե���isDogEmpty���������������Ƿ���dog ���ʵ��;
�û����Ե���isCatEmpty���������������Ƿ���cat���ʵ����
Ҫ���������з���ʱ�临�Ӷȶ���O(1)*/

struct Pet {
	Pet(string type) :
		type(type)
	{
	}

	string getPetType() {
		return type;
	}

protected:
	string type;
};

struct Dog : public Pet {
	Dog():
		Pet("dog")
	{
		
	}
};

struct Cat : public Pet {
	Cat() :
		Pet("cat")
	{

	}
};

struct PetInQ {
	Pet* pet;
	long timestamp;
	PetInQ(Pet* p, long t) {
		pet = p;
		timestamp = t;
	}

	Pet* getPet() {
		return pet;
	};

	long getTimestamp() {
		return timestamp;
	}

	string getPetType() {
		return pet->getPetType();
	}
};

class DogCatQueue {
public:
	DogCatQueue() :
		timestamp(0)
	{

	}

	void Add(Pet* pet) {
		if (pet->getPetType() == "dog") {
			dog_queue.push(new PetInQ(pet, timestamp++));
		}
		else if(pet->getPetType() == "cat"){
			cat_queue.push(new PetInQ(pet, timestamp++));
		}
		else {
			return;
		}
	};

	Pet* PollDog() {
		if (!dog_queue.empty()) {
			Pet* ret  = dog_queue.front()->getPet();
			dog_queue.pop();
			return  ret;
		}
	}

	Pet* PollCat() {
		if (!cat_queue.empty()) {
			Pet* ret = cat_queue.front()->getPet();
			cat_queue.pop();
			return ret;
		}
	}

	Pet* PollAll() {
		if (!cat_queue.empty() && !dog_queue.empty()) {
			if (cat_queue.front()->getTimestamp() < dog_queue.front()->getTimestamp()) {
				Pet* ret = cat_queue.front()->getPet();
				cat_queue.pop();
				return ret;
			}
			else {
				Pet* ret = dog_queue.front()->getPet();
				dog_queue.pop();
				return ret;
			}
		}
		if (!cat_queue.empty()) {
			Pet* ret = cat_queue.front()->getPet();
			cat_queue.pop();
			return ret;
		}
		if (!dog_queue.empty()) {
			Pet* ret = dog_queue.front()->getPet();
			dog_queue.pop();
			return ret;
		}
		return nullptr;
	}

private:
	long timestamp;
	queue<PetInQ*> dog_queue;
	queue<PetInQ*> cat_queue;
};