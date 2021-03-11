#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

struct info {
	double price, dis;
}gasStations[505];

bool cmp(info a, info b) {
	return a.dis < b.dis;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("D:\\work\\data.in","r",stdin);
    #endif
	int N, i;
	double D, D_avg, C;
	int ret = scanf("%lf %lf %lf %d", &C, &D, &D_avg, &N);
	for (i = 0; i < N; ++i) {
		ret = scanf("%lf %lf", &gasStations[i].price, &gasStations[i].dis);
	}
	double gas = 0, spend = 0;//�ֱ��ʾ��ǰ����������
	gasStations[i].price = 0, gasStations[i].dis = D;//����Ŀ�ĵ���һ����ѵļ���վ
	sort(gasStations, gasStations + N + 1, cmp);
	if (gasStations[0].dis > 0) {//���û�м���վ
		printf("The maximum travel distance = 0.00");
		return 0;
	}
	int now = 0;
	while (now < N) {
		int minP = -1;
		double priceMin = 1000000;//���������
		for (i = now + 1; i < N + 1 && gasStations[i].dis - gasStations[now].dis <= C * D_avg; ++i) {
			//�ҵ��ɴﷶΧ�ڼ۸����
			if (gasStations[i].price < priceMin) {
				minP = i;
				priceMin = gasStations[i].price;
				if (priceMin < gasStations[now].price) break;
			}
		}
		if (minP == -1) break;//����ɴﷶΧ��û�м���վ�����˳�ѭ��
		double gasNeed = (gasStations[minP].dis - gasStations[now].dis) / D_avg;//ȥ��һ������վ��Ҫ������
		if (priceMin > gasStations[now].price) {//��ǰ����վ�۸����
			spend += (C - gas) * gasStations[now].price;//������
			gas = C - gasNeed;
		}
		else {			
			if (gas >= gasNeed) {//�͹�
				gas -= gasNeed;
			}
			else {//�Ͳ���
				spend += (gasNeed - gas) * gasStations[now].price;
				gas = 0;
			}		
		}
		now = minP;
	}
	if (now == N) printf("%.2f\n", spend);
	else printf("The maximum travel distance = %.2f\n", gasStations[now].dis + C * D_avg);
	return 0;
}
