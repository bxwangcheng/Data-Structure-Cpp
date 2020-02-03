#pragma once
#include "Exercise00_NowcoderTools.h"
/*宠物、狗和猫的类如下:


实现一种狗猫队列的结构，要求如下:
用户可以调用add方法将cat类或dog类的 实例放入队列中;
用户可以调用pollAll方法，将队列中所有的实例按照进队列 的先后顺序依次弹出;
用户可以调用pollDog方法，将队列中dog类的实例按照 进队列的先后顺序依次弹出;
用户可以调用pollCat方法，将队列中cat类的实 例按照进队列的先后顺序依次弹出;
用户可以调用isEmpty方法，检查队列中是 否还有dog或cat的实例;
用户可以调用isDogEmpty方法，检查队列中是否有dog 类的实例;
用户可以调用isCatEmpty方法，检查队列中是否有cat类的实例。
要求以上所有方法时间复杂度都是O(1)*/

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