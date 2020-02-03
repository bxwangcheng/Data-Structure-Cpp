#pragma once
#include "Exercise00_NowcoderTools.h"
/*СQ���ڸ�һ������Ϊn�ĵ�·���·�ư��÷�����
Ϊ�����������,СQ�ѵ�·��Ϊn������,��Ҫ�����ĵط���'.'��ʾ, ����Ҫ
�������ϰ��������'X'��ʾ��СQ����Ҫ�ڵ�·������һЩ·��, ���ڰ�����
posλ�õ�·��, ��յ·�ƿ�������pos - 1, pos, pos + 1������λ�á�
СQϣ���ܰ��þ����ٵ�·����������'.'����, ϣ�����ܰ�������һ��������
Ҫ����յ·�ơ�
����������
����ĵ�һ�а���һ��������t(1 <= t <= 1000), ��ʾ����������
������ÿ����һ����������, ��һ��һ��������n(1 <= n <= 1000),��ʾ��·
�ĳ��ȡ��ڶ���һ���ַ���s��ʾ��·�Ĺ���,ֻ����'.'��'X'��
���������
����ÿ����������, ���һ����������ʾ������Ҫ����յ·�ơ�*/

int LightUpRoad(string arr) {
	if (arr.size() < 1) {
		return -1;
	}
}

// arr[index..]������Ҫ���ٵ�
// pre��ʾ֮ǰ��û�е���
int LightUpRoadProcess(string arr, bool pre, int index) {
	if (index == arr.size()) {
		return pre ? 0 : -1;
	}
	if (index == arr.size() - 1) {
		if (arr[index] == 'X' && pre) {
			return 0;
		}
		if (arr[index] == 'X' && !pre) {
			return -1;
		}
		return 1;
	}
	if (pre) {
		int p1 = LightUpRoadProcess(arr, false, index + 1);
		int p2 = LightUpRoadProcess(arr, true, index + 2);
		return p1 + p2;
	}
	else {

		return arr[index] == 'X' ? -1 : 1 + LightUpRoadProcess(arr, true, index + 1);
	}
	

}