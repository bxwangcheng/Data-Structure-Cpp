#pragma once
#include "Exercise00_NowcoderTools.h"
/*Ϊ���ҵ��Լ�����Ĺ�����ţţ�ռ���ÿ�ֹ������ѶȺͱ��ꡣţţѡ�����ı�׼�����ѶȲ�������������
ֵ������£�ţţѡ�񱨳���ߵĹ�������ţţѡ�����Լ��Ĺ�����ţţ��С���������ţţ��æѡ������
ţţ��Ȼʹ���Լ��ı�׼������С����ǡ�ţţ��С���̫���ˣ�������ֻ�ð�������񽻸����㡣
class Job {
public int money;// �ù����ı���
public int hard; // �ù������Ѷ�
public Job(int money, int hard) {
this.money = money;
this.hard = hard;
}
}
����һ��Job���͵�����jobarr����ʾ���еĹ���������һ��int���͵�����arr����ʾ����С����������
����int���͵����飬��ʾÿһ��С��鰴��ţţ�ı�׼ѡ���������ܻ�õı��ꡣ*/

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

