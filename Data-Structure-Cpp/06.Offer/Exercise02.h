#pragma once
//��ʵ��һ����������һ���ַ����е�ÿ���ո��滻�ɡ�%20����
//���磬���ַ���ΪWe Are Happy.�򾭹��滻֮����ַ���ΪWe%20Are%20Happy��


void replaceSpace(char* str, int length) {
	if (str == nullptr || length < 1)
		return;
	int old_len = 0;
	int space_count = 0;
	int i = 0;
	while (str[i] != '\0') {
		if (str[i] == ' ') {
			space_count++;
		}
		old_len++;
		i++;
	}
	int new_len = old_len + 2 * space_count;
	i = new_len;
	int j = old_len;
	char* new_str = new char;
	while (old_len >= 0 && i > j) {
		if (str[j] == ' ') {
			new_str[i--] = '0';
			new_str[i--] = '2';
			new_str[i--] = '%';
		}
		else {
			new_str[i--] = str[j];
		}
		j--;
	}
	str = new_str;
}