#pragma once
#include "Exercise00_NowcoderTools.h"
/*为了找到自己满意的工作，牛牛收集了每种工作的难度和报酬。牛牛选工作的标准是在难度不超过自身能力
值的情况下，牛牛选择报酬最高的工作。在牛牛选定了自己的工作后，牛牛的小伙伴们来找牛牛帮忙选工作，
牛牛依然使用自己的标准来帮助小伙伴们。牛牛的小伙伴太多了，于是他只好把这个任务交给了你。
class Job {
public int money;// 该工作的报酬
public int hard; // 该工作的难度
public Job(int money, int hard) {
this.money = money;
this.hard = hard;
}
}
给定一个Job类型的数组jobarr，表示所有的工作。给定一个int类型的数组arr，表示所有小伙伴的能力。
返回int类型的数组，表示每一个小伙伴按照牛牛的标准选工作后所能获得的报酬。*/

struct Job {
	int money;
	int hard;
	Job(int hard, int money) {
		this->money = money;
		this->hard = hard;
	};
};

//bool HardAscend(const Job& a, const Job& b) {
//	return a.hard < b.hard;
//}
//
//bool MoneyDescend(const Job& a, const Job& b) {
//	return a.money > b.money;
//}

struct CompareJob {
	bool operator()(const Job& a, const Job& b) const {
		return a.hard == b.hard ? a.money > b.money : a.hard < b.hard;
	}
};

bool compareJob(const Job& a, const Job& b) {
	return a.hard == b.hard ? a.money > b.money : a.hard < b.hard;
}

vector<int> MaxSalary(vector<Job>& job_arr, vector<int> power) {
	if (job_arr.size() < 1) {
		return {};
	}
	sort(job_arr.begin(), job_arr.end(), compareJob);
	map<int,int> useful_jobs;
	vector<int> res(power.size(),0);
	useful_jobs.insert(pair<int,int>(job_arr[0].hard, job_arr[0].money));
	for (int i = 1; i < job_arr.size(); i++) {
		if (job_arr[i - 1].hard < job_arr[i].hard && job_arr[i].money > job_arr[i-1].money) {
			useful_jobs.insert(pair<int,int>(job_arr[i].hard, job_arr[i].money));
		}
	}
	for (int i = 0; i < power.size(); i++) {
		if (useful_jobs.lower_bound(power[i]) != useful_jobs.end()) {
			res[i]=useful_jobs.lower_bound(power[i])->second;
		}
	}
	return res;
}

void TestExercise35() {
	Job a(1, 3);
	Job b(1, 2);
	Job c(2, 9);
	Job d(3, 11);
	Job e(3, 8);
	Job f(4, 6);
	Job g(4, 4);
	vector<Job> job_arr = {a,b,c,d,e,f,g};
	vector<int> pwr_arr = {1,2,3,4,5,6,7,8,9,10};
	auto res = MaxSalary(job_arr, pwr_arr);
}

