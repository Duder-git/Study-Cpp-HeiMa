

# �ݽ��������̹���ϵͳ

## 1�� �ݽ�������������

![1548154762048](E:/��Ƶѧϰ����/�������Ա����֮��-C++�̳�/����/assets/1548154762048.png)



### 1.1 ��������

* ѧУ����һ���ݽ�����������**12����**�μӡ�**����������**����һ��Ϊ��̭�����ڶ���Ϊ������
* ������ʽ��**���������ÿ��6����**��ѡ��ÿ��Ҫ������飬���б���
* ÿ��ѡ�ֶ��ж�Ӧ��**���**���� 10001 ~ 10012 
* ��һ�ַ�Ϊ����С�飬ÿ��6���ˡ� ���尴��ѡ�ֱ�Ž���**��ǩ**��˳���ݽ���
* ��С���ݽ������̭����������������ѡ�֣�**ǰ��������**��������һ�ֵı�����
* �ڶ���Ϊ������**ǰ����ʤ��**
* ÿ�ֱ���������Ҫ**��ʾ����ѡ�ֵ���Ϣ**

### 1.2 ������

* ��ʼ�ݽ����������������������̣�ÿ�������׶���Ҫ���û�һ����ʾ���û���������������һ���׶�
* �鿴�����¼���鿴֮ǰ����ǰ���������ÿ�α��������¼���ļ��У��ļ���.csv��׺������
* ��ձ�����¼�����ļ����������
* �˳��������򣺿����˳���ǰ����

### 1.3 ����Ч��ͼ��

![1548155966702](E:/��Ƶѧϰ����/�������Ա����֮��-C++�̳�/����/assets/1548155966702.png)



## 2�� ��Ŀ����

������Ŀ�������£�

- ��������Ŀ
- ����ļ�



### 2.1 ������Ŀ

* ��vs2017�󣬵����������Ŀ�������µ�C++��Ŀ

��ͼ��

![1548121881969](E:/��Ƶѧϰ����/�������Ա����֮��-C++�̳�/����/assets/1548121881969.png)



* ��д��Ŀ�����Լ�ѡȡ��Ŀ·�������ȷ��������Ŀ

![1548122271773](E:/��Ƶѧϰ����/�������Ա����֮��-C++�̳�/����/assets/1548122271773.png)



### 2.2 ����ļ�

* �Ҽ�Դ�ļ�����������ļ�����

![1548122420253](E:/��Ƶѧϰ����/�������Ա����֮��-C++�̳�/����/assets/1548122420253.png)

* ��д�ļ����ƣ�������

![1548122510869](E:/��Ƶѧϰ����/�������Ա����֮��-C++�̳�/����/assets/1548122510869.png)

* �����ļ��ɹ���Ч������ͼ

![1548122619712](E:/��Ƶѧϰ����/�������Ա����֮��-C++�̳�/����/assets/1548122619712.png)



* ���ˣ���Ŀ�Ѵ������





## 3�� ����������

**����������**

- �ṩ�˵��������û�����
- ���ݽ��������̽��п���
- ���ļ��Ķ�д����




### 3.1�����ļ�

* ��ͷ�ļ���Դ�ļ����ļ����·ֱ𴴽�speechManager.h �� speechManager.cpp�ļ�

![1548123402593](E:/��Ƶѧϰ����/�������Ա����֮��-C++�̳�/����/assets/1548123402593.png)



### 3.2 ͷ�ļ�ʵ��

��speechManager.h����ƹ�����

�������£�

```c++
#pragma once
#include<iostream>
using namespace std;

//�ݽ�������
class SpeechManager
{
public:

	//���캯��
	SpeechManager();


	//��������
	~SpeechManager();
};
```

### 3.3 Դ�ļ�ʵ��

��speechManager.cpp�н����������������ʵ�ֲ�ȫ

```c++
#include "speechManager.h"

SpeechManager::SpeechManager()
{
}

SpeechManager::~SpeechManager()
{
}
```

* �����ݽ��������Դ������



## 4�� �˵�����

�������������û��Ĺ�ͨ����

### 4.1 ��ӳ�Ա����

�ڹ�����speechManager.h����ӳ�Ա����  `void show_Menu();`

![1548123942072](E:/��Ƶѧϰ����/�������Ա����֮��-C++�̳�/����/assets/1548123942072.png)

 



### 4.2 �˵�����ʵ��

* �ڹ�����speechManager.cpp��ʵ�� show_Menu()����

```c++
void SpeechManager::show_Menu()
{
	cout << "********************************************" << endl;
	cout << "*************  ��ӭ�μ��ݽ����� ************" << endl;
	cout << "*************  1.��ʼ�ݽ�����  *************" << endl;
	cout << "*************  2.�鿴�����¼  *************" << endl;
	cout << "*************  3.��ձ�����¼  *************" << endl;
	cout << "*************  0.�˳���������  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}
```



### 4.3 ���Բ˵�����

* ���ݽ��������̹���ϵͳ.cpp�в��Բ˵�����

���룺

```c++
#include<iostream>
using namespace std;
#include "speechManager.h"

int main() {

	SpeechManager sm;

	sm.show_Menu();

	system("pause");

	return 0;
}
```

* ����Ч����ͼ��

![1548124599641](E:/��Ƶѧϰ����/�������Ա����֮��-C++�̳�/����/assets/1548124599641.png)

* �˵��������



## 5�� �˳�����

### 5.1  �ṩ���ܽӿ�

* ��main�������ṩ��֧ѡ���ṩÿ�����ܽӿ�

���룺

```c++
int main() {

	SpeechManager sm;

	int choice = 0; //�����洢�û���ѡ��

	while (true)
	{
		sm.show_Menu();

		cout << "����������ѡ�� " << endl;
		cin >> choice; // �����û���ѡ��

		switch (choice)
		{
		case 1:  //��ʼ����
			break;
		case 2:  //�鿴��¼
			break;
		case 3:  //��ռ�¼
			break;
		case 0:  //�˳�ϵͳ
			break;
		default:
			system("cls"); //����
			break;
		}
	}

	system("pause");

	return 0;
}
```



### 5.2 ʵ���˳�����

��speechManager.h���ṩ�˳�ϵͳ�ĳ�Ա���� `	void exitSystem();`

��speechManager.cpp���ṩ����Ĺ���ʵ��

```c++
void SpeechManager::exitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}
```



### 5.3���Թ���

��main������֧ 0  ѡ���У������˳�����Ľӿ�

![1548124853576](E:/��Ƶѧϰ����/�������Ա����֮��-C++�̳�/����/assets/1548124853576.png)



���в���Ч����ͼ��

![1548124888578](E:/��Ƶѧϰ����/�������Ա����֮��-C++�̳�/����/assets/1548124888578.png)



## 6���ݽ���������

### 6.1 ���ܷ���

�������̷�����

��ǩ �� ��ʼ�ݽ����� �� ��ʾ��һ�ֱ������ �� 

��ǩ �� ��ʼ�ݽ����� �� ��ʾǰ������� �� �������



### 6.2 ����ѡ����

* ѡ�����е����԰�����ѡ������������
* ͷ�ļ��д��� speaker.h�ļ�������Ӵ��룺

```C++
#pragma once
#include<iostream>
using namespace std;

class Speaker
{
public:
	string m_Name;  //����
	double m_Score[2]; //����  ��������ֵ÷�
};
```



### 6.3 ����

#### 6.3.1 ��Ա�������

* ��speechManager.h���������

```C++
	//����ѡ�� ����  12��
	vector<int>v1;

	//��һ�ֽ�������  6��
	vector<int>v2;

	//ʤ��ǰ��������  3��
	vector<int>vVictory;

	//��ű�� �Լ���Ӧ�� ����ѡ�� ����
	map<int, Speaker> m_Speaker;
```





#### 6.3.2 ��ʼ������

- ��speechManager.h���ṩ��ʼ�����ĵĳ�Ա���� `void initSpeech();`

```c++
	//��ʼ������
	void initSpeech();
```



- ��speechManager.cpp��ʵ��`void initSpeech();`

```c++
void SpeechManager::initSpeech()
{
	//������֤Ϊ��
	this->v1.clear();  
	this->v2.clear();
	this->vVictory.clear();
	this->m_Speaker.clear();
	//��ʼ����������
	this->m_Index = 1;
}
```



- SpeechManager���캯���е���`void initSpeech();`

```c++
SpeechManager::SpeechManager()
{
	//��ʼ������
	this->initSpeech();
}
```





#### 6.3.3 ����ѡ��

* ��speechManager.h���ṩ��ʼ�����ĵĳ�Ա���� `void createSpeaker();`

```C++
	//��ʼ������12��ѡ��
	void createSpeaker();
```



* ��speechManager.cpp��ʵ��`void createSpeaker();`

```C++
void SpeechManager::createSpeaker()
{
	string nameSeed = "ABCDEFGHIJKL";
	for (int i = 0; i < nameSeed.size(); i++)
	{
		string name = "ѡ��";
		name += nameSeed[i];

		Speaker sp;
		sp.m_Name = name;
		for (int i = 0; i < 2; i++)
		{
			sp.m_Score[i] = 0;
		}

		//12��ѡ�ֱ��
		this->v1.push_back(i + 10001);

		//ѡ�ֱ�� �Լ���Ӧ��ѡ�� ��ŵ�map������
		this->m_Speaker.insert(make_pair(i + 10001, sp));
	}
}
```



* SpeechManager��� ���캯���е���`void createSpeaker();`

```C++
SpeechManager::SpeechManager()
{
    //��ʼ������
	this->initSpeech();
    
	//����ѡ��
	this->createSpeaker();
}
```



* ���� ��main�����У������ڴ������������ʹ�����д������12��ѡ�ֳ�ʼ״̬

```C++
for (map<int, Speaker>::iterator it = sm.m_Speaker.begin(); it != sm.m_Speaker.end(); it++)
{
	cout  << "ѡ�ֱ�ţ�" << it->first 
          << " ������ " << it->second.m_Name 
          << " �ɼ��� " << it->second.m_Score[0] << endl;
}
```

![1548141605742](E:/��Ƶѧϰ����/�������Ա����֮��-C++�̳�/����/assets/1548141605742.png)

* ����Ч����ͼ��

![1548141560164](E:/��Ƶѧϰ����/�������Ա����֮��-C++�̳�/����/assets/1548141560164.png)

* ������Ϻ󣬿��Խ����Դ���ɾ����ע�͡�





#### 6.3.4 ��ʼ������Ա�������

* ��speechManager.h���ṩ��ʼ�����ĵĳ�Ա���� `void startSpeech();`
* �ú�����������Ҫ���Ʊ���������

```C++
	//��ʼ���� - �������̿���
	void startSpeech();
```



* ��speechManager.cpp�н�startSpeech�Ŀ�ʵ����д��
* ���ǿ����Ƚ��������������� д��������

```C++
//��ʼ����
void SpeechManager::startSpeech()
{
	//��һ�ֱ���
	//1����ǩ
	
	//2������

	//3����ʾ�������

	//�ڶ��ֱ���

	//1����ǩ

	//2������

	//3����ʾ���ս��

	//4���������
}

```



#### 6.3.5 ��ǩ

**����������**

* ��ʽ����ǰ������ѡ�ֵı���˳����Ҫ���ң�����ֻ��Ҫ�����ѡ�ֱ�ŵ�����  ���Ҵ��򼴿�



* ��speechManager.h���ṩ��ǩ�ĵĳ�Ա���� `void speechDraw();`

```C++
	//��ǩ
	void speechDraw();
```



- ��speechManager.cpp��ʵ�ֳ�Ա���� `void speechDraw();`

```C++
void SpeechManager::speechDraw()
{
	cout << "�� << " << this->m_Index << " >> �ֱ���ѡ�����ڳ�ǩ"<<endl;
	cout << "---------------------" << endl;
	cout << "��ǩ���ݽ�˳�����£�" << endl;
	if (this->m_Index == 1)
	{
		random_shuffle(v1.begin(), v1.end());
		for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	else
	{
		random_shuffle(v2.begin(), v2.end());
		for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	cout << "---------------------" << endl;
	system("pause");
	cout << endl;
}
```



* ��startSpeech�������̿��Ƶĺ����У����ó�ǩ����

![1548143871202](E:/��Ƶѧϰ����/�������Ա����֮��-C++�̳�/����/assets/1548143871202.png)

* ��main�����У���֧1ѡ���У����ÿ�ʼ�����Ľӿ�

![1548143543475](E:/��Ƶѧϰ����/�������Ա����֮��-C++�̳�/����/assets/1548143543475.png)



* ����

![1548143610682](E:/��Ƶѧϰ����/�������Ա����֮��-C++�̳�/����/assets/1548143610682.png)



#### 6.3.6 ��ʼ����

* ��speechManager.h���ṩ�����ĵĳ�Ա���� `void speechContest();`

```C++
	//����
	void speechContest();
```



* ��speechManager.cpp��ʵ�ֳ�Ա���� `void speechContest();`

```C++
void SpeechManager::speechContest()
{
	cout << "------------- ��"<< this->m_Index << "����ʽ������ʼ��------------- " << endl;

	multimap<double, int, greater<int>> groupScore; //��ʱ����������key���� value ѡ�ֱ��

	int num = 0; //��¼��Ա����6��Ϊ1��

	vector <int>v_Src;   //��������Ա����
	if (this->m_Index == 1)
	{
		v_Src = v1;
	}
	else
	{
		v_Src = v2;
	}

	//�������в���ѡ��
	for (vector<int>::iterator it = v_Src.begin(); it != v_Src.end(); it++)
	{
		num++;

		//��ί���
		deque<double>d;
		for (int i = 0; i < 10; i++)
		{
			double score = (rand() % 401 + 600) / 10.f;  // 600 ~ 1000
			//cout << score << " ";
			d.push_back(score);
		}

		sort(d.begin(), d.end(), greater<double>());				//����
		d.pop_front();												//ȥ����߷�
		d.pop_back();												//ȥ����ͷ�

		double sum = accumulate(d.begin(), d.end(), 0.0f);				//��ȡ�ܷ�
		double avg = sum / (double)d.size();									//��ȡƽ����

		//ÿ����ƽ����
		//cout << "��ţ� " << *it  << " ѡ�֣� " << this->m_Speaker[*it].m_Name << " ��ȡƽ����Ϊ�� " << avg << endl;  //��ӡ����
		this->m_Speaker[*it].m_Score[this->m_Index - 1] = avg;

		//6����һ�飬����ʱ��������
		groupScore.insert(make_pair(avg, *it));
		if (num % 6 == 0)
		{

			cout << "��" << num / 6 << "С��������Σ�" << endl;
			for (multimap<double, int, greater<int>>::iterator it = groupScore.begin(); it != groupScore.end(); it++)
			{
				cout << "���: " << it->second << " ������ " << this->m_Speaker[it->second].m_Name << " �ɼ��� " << this->m_Speaker[it->second].m_Score[this->m_Index - 1] << endl;
			}

			int count = 0;
			//ȡǰ����
			for (multimap<double, int, greater<int>>::iterator it = groupScore.begin(); it != groupScore.end() && count < 3; it++, count++)
			{
				if (this->m_Index == 1)
				{
					v2.push_back((*it).second);
				}
				else
				{
					vVictory.push_back((*it).second);
				}
			}

			groupScore.clear();

			cout << endl;

		}
	}
	cout << "------------- ��" << this->m_Index << "�ֱ������  ------------- " << endl;
	system("pause");
}
```



* ��startSpeech�������̿��Ƶĺ����У����ñ�������

![1548144491984](E:/��Ƶѧϰ����/�������Ա����֮��-C++�̳�/����/assets/1548144491984.png)



* �ٴ����д��룬���Ա���

![1548144765146](E:/��Ƶѧϰ����/�������Ա����֮��-C++�̳�/����/assets/1548144765146.png)



#### 6.3.7 ��ʾ��������

* ��speechManager.h���ṩ�����ĵĳ�Ա���� `void showScore();`

```C++
	//��ʾ�������
	void showScore();
```



* ��speechManager.cpp��ʵ�ֳ�Ա���� `void  showScore();`

```C++
void SpeechManager::showScore()
{
	cout << "---------��" << this->m_Index << "�ֽ���ѡ����Ϣ���£�-----------" << endl;
	vector<int>v;
	if (this->m_Index == 1)
	{
		v = v2;
	}
	else
	{
		v = vVictory;
	}

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "ѡ�ֱ�ţ�" << *it << " ������ " << m_Speaker[*it].m_Name << " �÷֣� " << m_Speaker[*it].m_Score[this->m_Index - 1] << endl;
	}
	cout << endl;

	system("pause");
	system("cls");
	this->show_Menu(); 
}
```

* ��startSpeech�������̿��Ƶĺ����У�������ʾ������������

![1548146903960](E:/��Ƶѧϰ����/�������Ա����֮��-C++�̳�/����/assets/1548146903960.png)

* ���д��룬����Ч��

![1548146961550](E:/��Ƶѧϰ����/�������Ա����֮��-C++�̳�/����/assets/1548146961550.png)



#### 6.3.8 �ڶ��ֱ���

�ڶ��ֱ�������ͬ��һ�֣�ֻ�Ǳ���������+1���������̲���

* ��startSpeech�������̿��Ƶĺ����У�����ڶ��ֵ�����

![1548148593215](E:/��Ƶѧϰ����/�������Ա����֮��-C++�̳�/����/assets/1548148593215.png)



���ԣ��������������̶���ͨ

![1548148536395](E:/��Ƶѧϰ����/�������Ա����֮��-C++�̳�/����/assets/1548148536395.png)



### 6.4 �������

**����������**

* ��ÿ���ݽ������ĵ÷ּ�¼���ļ���

**����ʵ�֣�**

* ��speechManager.h����ӱ����¼�ĳ�Ա���� `void saveRecord();`

```C++
	//�����¼
	void saveRecord();
```



* ��speechManager.cpp��ʵ�ֳ�Ա���� `void saveRecord();`

```C++
void SpeechManager::saveRecord()
{
	ofstream ofs;
	ofs.open("speech.csv", ios::out | ios::app); // ������ķ�ʽ���ļ�  -- д�ļ�

	//��ÿ��������д�뵽�ļ���
	for (vector<int>::iterator it = vVictory.begin(); it != vVictory.end(); it++)
	{
		ofs << *it << ","
			<< m_Speaker[*it].m_Score[1] << ",";
	}
	ofs << endl;
    
	//�ر��ļ�
	ofs.close();
    
	cout << "��¼�Ѿ�����" << endl;
}
```



* ��startSpeech�������̿��Ƶĺ����У������ñ����¼��������

![1548149937860](E:/��Ƶѧϰ����/�������Ա����֮��-C++�̳�/����/assets/1548149937860.png)



* ���ԣ�����������Ϻ��¼�������

![1548149912863](E:/��Ƶѧϰ����/�������Ա����֮��-C++�̳�/����/assets/1548149912863.png)



���ü��±����ļ� speech.csv�����汣����ǰ����ѡ�ֵı���Լ��÷�

![1548150047975](E:/��Ƶѧϰ����/�������Ա����֮��-C++�̳�/����/assets/1548150047975.png)



���ˣ������ݽ���������������ϣ�



## 7�� �鿴��¼

### 7.1 ��ȡ��¼����



* ��speechManager.h����ӱ����¼�ĳ�Ա���� `void loadRecord();`
* ����ж��ļ��Ƿ�Ϊ�յı�־  `bool fileIsEmpty;`
* ��������¼������`map<int, vector<string>> m_Record;`   

����m_Record �е�key����ڼ��죬value��¼�������Ϣ

```C++
	//��ȡ��¼
	void loadRecord();

	//�ļ�Ϊ�յı�־
	bool fileIsEmpty;

	//�����¼
	map<int, vector<string>> m_Record;
```



* ��speechManager.cpp��ʵ�ֳ�Ա���� `void loadRecord();`

```C++
void SpeechManager::loadRecord()
{
	ifstream ifs("speech.csv", ios::in); //���������� ��ȡ�ļ�

	if (!ifs.is_open())
	{
		this->fileIsEmpty = true;
		cout << "�ļ������ڣ�" << endl;
		ifs.close();
		return;
	}

	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "�ļ�Ϊ��!" << endl;
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}

	//�ļ���Ϊ��
	this->fileIsEmpty = false;

	ifs.putback(ch); //��ȡ�ĵ����ַ��Ż�ȥ

	string data;
	int index = 0;
	while (ifs >> data)
	{
		//cout << data << endl;
		vector<string>v;

		int pos = -1;
		int start = 0;

		while (true)
		{
			pos = data.find(",", start); //��0��ʼ���� ','
			if (pos == -1)
			{
				break; //�Ҳ���break����
			}
			string tmp = data.substr(start, pos - start); //�ҵ���,���зָ� ����1 ��ʼλ�ã�����2 ��ȡ����
			v.push_back(tmp);
			start = pos + 1;
		}

		this->m_Record.insert(make_pair(index, v));
		index++;
	}

	ifs.close();
}
```



* ��SpeechManager���캯���е��û�ȡ�����¼����

![1548151977242](E:/��Ƶѧϰ����/�������Ա����֮��-C++�̳�/����/assets/1548151977242.png)



### 7.2 �鿴��¼����

* ��speechManager.h����ӱ����¼�ĳ�Ա���� `void showRecord();`

```C++
	//��ʾ����÷�
	void showRecord();
```



* ��speechManager.cpp��ʵ�ֳ�Ա���� `void showRecord();`

```C++
void SpeechManager::showRecord()
{
	for (int i = 0; i < this->m_Record.size(); i++)
	{
		cout << "��" << i + 1 << "�� " <<
			"�ھ���ţ�" << this->m_Record[i][0] << " �÷֣�" << this->m_Record[i][1] << " "
			"�Ǿ���ţ�" << this->m_Record[i][2] << " �÷֣�" << this->m_Record[i][3] << " "
			"������ţ�" << this->m_Record[i][4] << " �÷֣�" << this->m_Record[i][5] << endl;
	}
    system("pause");
	system("cls");
}
```



### 7.3 ���Թ���

��main������֧ 2  ѡ���У����ò鿴��¼�Ľӿ�

![1548152359604](E:/��Ƶѧϰ����/�������Ա����֮��-C++�̳�/����/assets/1548152359604.png)

��ʾЧ����ͼ�������β��������4����¼��

![1548152394715](E:/��Ƶѧϰ����/�������Ա����֮��-C++�̳�/����/assets/1548152394715.png)



### 7.4 bug���

Ŀǰ�������м���bugδ�����

1. �鿴�����¼�����ļ������ڻ�Ϊ�գ���δ��ʾ

�����ʽ����showRecord�����У���ʼ�ж��ļ�״̬�������ж�

![1548152803116](E:/��Ƶѧϰ����/�������Ա����֮��-C++�̳�/����/assets/1548152803116.png)



2. ����¼Ϊ�ջ򲻴��ڣ�����������Ȼ��ʾ��¼Ϊ��

�����ʽ��saveRecord�и����ļ�Ϊ�յı�־

![1548153005042](E:/��Ƶѧϰ����/�������Ա����֮��-C++�̳�/����/assets/1548153005042.png)

3. ��������鲻����������ļ�¼��û��ʵʱ����

�����ʽ��������Ϻ�������������

![1548153319587](E:/��Ƶѧϰ����/�������Ա����֮��-C++�̳�/����/assets/1548153319587.png)



4. �ڳ�ʼ��ʱ��û�г�ʼ����¼����

�����ʽ��initSpeech����� ��ʼ����¼����

![1548154340974](E:/��Ƶѧϰ����/�������Ա����֮��-C++�̳�/����/assets/1548154340974.png)

5. ÿ�μ�¼����һ����

�����ʽ����main����һ��ʼ ������������

```C++
srand((unsigned int)time(NULL));
```



����bug����� ���ԣ�

![1548153571603](E:/��Ƶѧϰ����/�������Ա����֮��-C++�̳�/����/assets/1548153571603.png)



## 8�� ��ռ�¼

### 8.1 ��ռ�¼����ʵ��

* ��speechManager.h����ӱ����¼�ĳ�Ա���� `void clearRecord();`

```C++
	//��ռ�¼
	void clearRecord();
```



* ��speechManager.cpp��ʵ�ֳ�Ա���� `void clearRecord();`

```C++
void SpeechManager::clearRecord()
{
	cout << "ȷ����գ�" << endl;
	cout << "1��ȷ��" << endl;
	cout << "2������" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		//��ģʽ ios::trunc �������ɾ���ļ������´���
		ofstream ofs("speech.csv", ios::trunc);
		ofs.close();

		//��ʼ������
		this->initSpeech();

		//����ѡ��
		this->createSpeaker();

		//��ȡ�����¼
		this->loadRecord();
		

		cout << "��ճɹ���" << endl;
	}

	system("pause");
	system("cls");
}
```

### 8.2 �������

��main������֧ 3  ѡ���У�������ձ�����¼�Ľӿ�

![1548154674242](E:/��Ƶѧϰ����/�������Ա����֮��-C++�̳�/����/assets/1548154674242.png)

���г��򣬲�����ռ�¼��

![1548154004738](E:/��Ƶѧϰ����/�������Ա����֮��-C++�̳�/����/assets/1548154004738.png)

speech.csv�м�¼ҲΪ��

![1548154508831](E:/��Ƶѧϰ����/�������Ա����֮��-C++�̳�/����/assets/1548154508831.png)



* ���˱����������� `^_^`