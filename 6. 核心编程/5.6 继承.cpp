#include "extend.h";

class BasePage {
public:
	int publica;
	void public_header() {
		cout << "public_header" << endl;
	}
protected:
	int publicb;
	void protected_footer() {
		cout << "protected_footer" << endl;
	}
private:
	int publicc;
	// 私有属性 子类不管如何调用都无法成功
	void private_left() {
		cout << "private_left" << endl;
	}
};

// 语法：class 子类 : 继承方式 父类
// 子类又叫派生类，父类又叫基类

// 公共继承 把父类的属性变为自己的属性 不会改变属性的特性
class Java:public BasePage {
	// parent public -> son public
	// parent protected -> son protected
public:
	int j;
	void content() {
		cout << "java content" << endl;
	}
	void test() {
		public_header();
		protected_footer();
		// left(); // 无法调用
	}

};

// 保护继承
class Python :protected BasePage {
	// parent public -> son protected
	// parent protected -> son protected
public:
	void content() {
		cout << "Python content" << endl;
	}
	void test() {
		public_header();
		protected_footer();
		// left(); // 无法调用
	}
};
// 私有继承
class Cpp :private BasePage {
	// parent public -> son private
	// parent protected -> son private
public:
	void content() {
		cout << "Cpp content" << endl;
	}
	void test() {
		public_header();
		protected_footer();
		// left(); // 无法调用
	}
};

class Cpp2 : public Cpp {
	void test() {
		//public_header(); // 父类的私有属性
		//protected_footer(); // 父类的私有属性
	}
};

void extendTest01() {
	cout << "_______java_______" << endl;
	Java ja;
	ja.public_header();
	// ja.protected_footer(); // 无法调用了，已经变成了自己protected属性
	// ja.private_left(); // 父类私有属性 无法调用
	ja.content();

	cout << "_______python_______" << endl;
	Python py;
	// py.public_header(); // 无法调用了，已经变成了自己protected属性
	// py.protected_footer(); // 无法调用了，已经变成了自己protected属性
	// py.private_left(); // 父类私有属性 无法调用
	py.content();
	cout << "_______cpp_______" << endl;
	Cpp cp;
	// cp.public_header(); // 无法调用了，已经变成了自己priavte属性
	// cp.protected_footer(); // 无法调用了，已经变成了自己priavte属性
	// cp.private_left(); // 父类私有属性 无法调用
	cp.content();
}

void extendTest02() {
	Java ja; 
	// 16 说明是四个属性都有了，私有属性虽然访问不到，但是也继承下来了，只不过被编译器隐藏了
	cout <<"sizeof ja = " << sizeof ja << endl; 

	// 或者 通过开发人员命令提示工具
	// 跳到文件位置 执行 cl /d1 reportSingleClassLayout类名 "文件名"
	// 跳到文件位置 执行 cl /d1 reportSingleClassLayoutJava "5.6 继承.cpp"
	/*
	class Java      size(16) :
	+-- -
	0 | +-- - (base class BasePage)
	0      | | publica
	4      | | publicb
	8      | | publicc
	| +-- -
	12 | j
	*/
}


void classExtend() {
	// 继承
	extendTest01();
	// 对象属性
	extendTest02();

}