// 马而科夫链——保险.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<math.h>
using namespace std;
struct Chainpoint {//构造马尔科夫链节点
    int flag;//flag为1表示high，为0表示low
    double possibility;
};
void layposscount(Chainpoint A[],int hight) {
    double highposs=0;
    for (int i = 2; i <= hight; i++) {
        for (int j = pow(2, (i - 1)); j <= pow(2, i) - 1; j += 2)
            highposs += A[j].possibility;
        cout << "第"<<i<<"层的high概率和为" << highposs << '\t' << "第" << i << "层的low概率和为" << 1 - highposs << endl;
        highposs = 0;
    }
}

void Chainbuild(int hight, double high_highposs, double high_lowposs,double low_highposs,double low_lowposs) {
    double count = pow(2, hight) - 1;
    if (count <= 2) 
        cout << "输入层数过小，无法形成马尔科夫链，请重新开始本程序" << endl;
    Chainpoint chain[1030];//链长不超过10层
    chain[2].flag = 1;
    chain[2].possibility = 0.5;
    chain[3].flag = 0;
    chain[3].possibility = 0.5;
    for (int i = 4; i <= count; i++) {
        if (i % 2 == 0) {
            chain[i].flag = 1;
            if (chain[i / 2].flag ==1)
                chain[i].possibility = (chain[i / 2].possibility) * high_highposs;
            else
                chain[i].possibility = (chain[i / 2].possibility) * low_highposs;
        }
        else 
        {
            chain[i].flag = 0;
            if (chain[i / 2].flag ==1)
                chain[i].possibility = (chain[i / 2].possibility) * high_lowposs;
            else
                chain[i].possibility = (chain[i / 2].possibility) * low_lowposs;
        }
    }
    layposscount(chain, hight);//如果引用传参可以写为：layposscount(&chain, &hight)
}
int main()
{
    int hight;
    double high_high, high_low, low_high, low_low;
    cout << "请输入high_high,high_low,low_high,low_low的概率" << endl;
    cin >> high_high >> high_low >> low_high >> low_low;
    cout << "请输入马尔科夫链的层数：" << endl;
    cin >> hight;
    Chainbuild(hight, high_high, high_low, low_high, low_low);
    return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
