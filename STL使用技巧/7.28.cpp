

//STL容器 vector(变长数组)，string（substr()，c_str()），queue（push()队尾插入，front（）队头元素，pop（）队头弹出，back（）队尾），
//priority_queue(堆)（push（）插入，top（顶上的元素），pop（）弹出第一个元素），stack（push（），top（），pop（）），deque（双端队列，可以从两头插入弹出），
// set，map，multiset，multimap，基于平衡二叉树（红黑树）动态维护有序队列
//unordered_set，unordered_map，unordered_multiset， unordered_multimap这几个是基于哈希表
//bitset位存储，状态压缩，压位
//pair
//list

//for(auto item:a)可以遍历所有容器

#include<bits/stdc++.h>
using namespace std;

int main()
{
	vector<int> a(10, 5);//共10个元素，每个都赋值成5
	vector<int> b[5];//一个二维数组
	b[0].push_back(1);
	vector<int> c(a);//用一个vector给另一个赋值
	vector<int> d(a.begin(), a.begin() + 3);//下标0开始共3个
	int e[5] = { 0,1,2,3,4 };
	vector<int> f(e, e + 5);//也能用e这样的数组来给vector赋值

	a.size();//返回vector中元素个数
	a.empty();//空的返回true，非空返回false                    这两个所有容器都有，复杂度O(1)
	a.clear();//清空
	a.front();//返回vector第一个数
	a.back();//返回vector最后一个数
	a.push_back(0);//在vector后面插入一个数
	a.pop_back();//把vector最后一个数删掉
	a.begin();   // vector也有迭代器，begin是第0个数  可以看成是指针，可以解引用 *i
	a.end();     //end是最后一个数的后一个数
	//vector支持随机寻址，和数组一样

	//vector支持比较运算，比如一个vector里3个4，一个里面4个3，那么3个4的更大

	a.erase();//删除是O（n）的

	for (int i = 0; i < a.size(); i++)cout << a[i];
	for (vector<int>::iterator i = a.begin(); i != a.end(); i++)cout << *i;            //两种遍历方式，当然也可以for(auto item:a)，vector<int>::iterator可以写成auto

	//申请空间的速度和空间大小没关系，和申请次数有关系，申请1和1000的速度一样，但申请1000和申请1000次1，时间差1000倍
	//所以vector有倍增的思想，例如一开始分配32的空间，不够用就分配64个，把那32个复制到前面，64不够用就分配128个，再把那64个复制过去，128够用就128个
	//所以vector如果有n个元素需要放进去，到最后是复制了log2n次，总共复制了n个数，均摊下来每个数O(1)，
	//所以%%%%%%%%%%%%%%vector每插入一个数，复杂度O(1)%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	//**************************************************************************************************************************************************************************
	pair<int,string> g;
	g.first = 1;
	g.second = 2;
	//pair支持比较运算,pair按字典序比，以第一个为第一关键字
	g = make_pair(2, "ljp");
	g = { 2,"ljp" };
	pair<int, pair<int, int>> i;   //pair也可以存储三个
	//****************************************************************************************************************************************************************************
	string j;   //string 可以做 栈
	string还有个find函数  str.find("abc"或'a',0)指从下标0开始找字符串或字符，返回第一个下标,也可以从其他下标开始找
	j.back();
	j.size();  // 字符串中字符个数
	j.length();//作用同size()%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	j.empty();
	j.clear();
	j += "ljp";
	j.substr(1, 2);//  j的一个子串，第一个参数是从哪个下标开始，第二个参数是长度,如果超出原长，则只输出到最后一个字符为止,也可以省略第二个参数，则返回从那个下标开始的整个子串
	printf("%s", j);//  这样输出不对，输出的不是原来的内容
	printf("%s", j.c_str());//   这样才能输出正确的内容   c_str()返回的是存储字符串的字符数组的 起始地址
	//*********************************************************************************************************************************************************************
	queue<int> k;
	k.size();
	k.empty();
	k.push(5);
	k.front();
	k.back();
	k.pop();
	//queue,priority_queue,stack没有clear函数，想要清空是 k = queue<int>();
	k = queue<int>();
	//**************************************************************************************************************************************************************************
	priority_queue<int> heap;         //  默认是大根堆(队头是最大的)
	//  如果想变成小根堆，可以push的时候push（-x）  或者   直接定义成小根堆
	//直接定义小根堆  ： 需要vector
	priority_queue<int, vector<int>, greater<int>> heap2;  //小根堆
	heap.push(5);//        向堆中插入一个元素
	heap.top(); //          返回队顶元素
	heap.pop();//        弹出队顶元素
	//************************************************************************************************************************************************************************
	stack<int> m;
	m.push(5);
	m.top();
	m.pop();
	m.size();
	m.empty();
	// 时间复杂度是O(1)的
	//**************************************************************************************************************************************************************************
	deque<int> n;  //   加强版vector   速度相对较慢所以用的不多
	n.size();
	n.empty();
	n.clear();
	n.front();
	n.back();
	n.push_back(5);
	n.pop_back();
	n.push_front(5);
	n.pop_front();
	//deque 支持随机寻址
	n.begin();
	n.end();  //  有迭代器
	//********************************************************************************************************************************************************************
	set<int> o;//  set里不能有重复元素，如果插入一个重复元素，这个操作会被忽略，set所有操作时间复杂度log2n,size(),empty(),clear()是 O(1)
	o.size();
	o.empty();
	o.clear();
	o.insert(5);
	o.find(5);    // find查找一个数，不存在返回end迭代器
	o.count(5);  //  返回某个数的个数
	o.erase(5);//两种参数，如果输入一个数，那么删除所有等于这个数的  O（k+log2n）k是这个数的个数，如果输入迭代器，删除这个迭代器
	o.lower_bound(6);   // 返回大于等于x的最小的数 的迭代器
	o.upper_bound(6);  //   返回大于x的最小的数 的迭代器        两个都是如果不存在返回end迭代器   set最核心的两个操作   
	multiset<int> p;  //  multiset里可以有重复元素
	p.size();
	p.empty();
	p.clear();
	p.insert(5); // find查找一个数，不存在返回end迭代器
	p.count(5); //  返回某个数的个数
	p.erase(5);//两种参数，如果输入一个数，那么删除所有等于这个数的  O（k+log2n）k是这个数的个数，如果输入迭代器，删除这个迭代器
	p.lower_bound(6);
	p.upper_bound(6);
	//*******************************************************************************************************************************************************************
	//map,multimap,set,multiset都有迭代器，迭代器++或--(时间复杂度O(log2n))返回的是前驱和后继（前面一个数和后面一个数）
	//map里存的是两个东西，把一个东西映射到另一个东西
	map<int,string> q;        //int映射成string
	multimap<int,string> r;

	q[1] = "ljp";    //  插入，1就映射到ljp    ，像用数组一样用map  时间复杂度O(log2n)

	q.insert({ 1,"ljp" });  //  insert参数是一个pair
	r.insert({5,"ljp"});
	q.erase(5); //  erase参数是一个pair，或迭代器
	r.erase(5);
	q.find(5);  
	r.find(5);  //   像数组用下标找一样，这里是 得到ljp
	q.lower_bound(5);
	r.lower_bound(5);
	q.upper_bound(5);
	r.upper_bound(5);
	
	
	//基本上set，map所有操作都是log2n，除了size(),empty(),clear()
	//****************************************************************************************************************************************************************************
	//unodered的所有的，和上面类似，是对应的，没有顺序，增删改查时间复杂度O(1)，没有lower_bound,upper_bound，和迭代器的++，--（没有和顺序有关的东西）
	//*****************************************************************************************************************************************************************************
	//1024字节(bool类型数组大小1024) = 1024B = 1KB
	//bitset可以省8倍空间(原来的1/8)。原来用1个字节存的东西，现在存到一位上去，节省了8倍空间，同时速度会变慢，时间变长
	bitset<10000> s;   //  其他的尖括号是类型，这里是个数，定义了长度为一万的bitset
	~s, & s, ^ s, | s;//    支持 取反，与，或，异或，左移，右移，==，！=运算符
	//   支持中括号  []  可以取出某一位 是0是1  
	//支持  count函数，返回多少个 1
	//支持  any ，none 函数，any返回是否至少有一个一，none判断是否全为 0
	s.set(); // 把所有位 变成 1
	s.set(k, v); //  将第k位变成 v 
	s.reset(); // 将所有位变成  0
	s.flip();  // 把所有位取反 ，等价于 ~ 
	s.flip(k);  //  把第 k 位取反



	return 0;
}
/*
 vector<int> f;
	for (int i = 1; i <=5; ++i) {
		f.push_back(i * 2);
		f.push_back(i * 2);
	}
	
	f中的数据为
	下标0   1   2   3   4   5   6   7   8   9
	    2   2   4   4   6   6   8   8   10  10
	
cout << lower_bound(f.begin(), f.end(), 1) - f.begin() << endl;
//输出 0
cout << lower_bound(f.begin(), f.end(), 6) - f.begin() << endl;
//输出 4
cout << upper_bound(f.begin(), f.end(), 6) - f.begin() << endl;
//输出 6
cout << lower_bound(f.begin(), f.end(), 10) - f.begin() << endl;
//输出 8
cout << upper_bound(f.begin(), f.end(), 10) - f.begin() << endl;
//输出 10
cout << lower_bound(f.begin(), f.end(), 11) - f.begin() << endl;
//输出 10
*/
/*
 v.insert(v.begin(),8);//在最前面插入新元素,此时v为8 2 7 9 5
	v.insert(v.begin()+3,1);//在迭代器中下标为3的元素前插入新元素,此时v为8 2 7 1 9 5
	v.insert(v.end(),3);//在向量末尾追加新元素,此时v为8 2 7 1 9 5 3
	v.insert(v.end(),3,0);//在尾部插入3个0,此时v为8 2 7 1 9 5 3 0 0 0
————————————————
*/
/*
sort(alls.begin(), alls.end());                                          //   排序去重
	alls.erase(unique(alls.begin(), alls.end()), alls.end());
	*/
/*
   map<int, int> mp;
	int mx = -1;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		++mp[a[i]];
		mx = max(mx, a[i]);
	}
	sort(a, a + n);
	int j = 0;
	for (int i = 0; i < n; ++i) {
		if (!i || a[i] != a[i-1]) {
			a[j++] = a[i];
		}
	}                                                    记录数组中每个元素出现次数，排序去重
*/


map的底层是红黑树，unordered_map底层是哈希表(unordered即无序)
set的底层也是红黑树
学过二叉查找树的同学都知道，普通的二叉查找树在极端情况下可退化成链表，此时的增删查效率都会比较低下,为了避免这种情况，就出现了一些自平衡的查找树，比如 AVL，红黑树等

map的键与值一一对应，可以不同，set的键与值必须相同，multimap一个键可对应多个值
map、multimap 容器都会自行根据键的大小对存储的键值对进行排序，set 容器也会如此，只不过 set 容器中各键值对的键 key 和值 value 是相等的，根据 key 排序，也就等价为根据 value 排序。
to_chars是c++17的函数
// puts输出字符串，输出时将最后的\0输出为回车
strtol将一个进制的字符串转换成十进制的long
to_chars将一个十进制的数转换成n进制的字符串，其中英文字母小写

vector<int> v(n)表示声明一个容器v，并给他预定存储空间。每一个单元初始化为0，因此，vector<int> v(n)也等同于vector<int> v(n, 0)。当然，如果想要初始化为其他值，也可以改为vector<int> v(n, val)
vector＜int＞ v[n]可以理解为定义了一个长度为n的数组，数组的每个元素都是一个vector类型的变量。这个v[n]可以理解为一维长度是n，二维长度可变的矩阵。

//一个数左移1位就是乘以2，左移n位就是乘以2的n次方（而左移运算比乘法快得多）右移n位就是除以2的n次方，当得到的商不是整数时会往小取整

