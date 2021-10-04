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
	// ˽������ ���಻����ε��ö��޷��ɹ�
	void private_left() {
		cout << "private_left" << endl;
	}
};

// �﷨��class ���� : �̳з�ʽ ����
// �����ֽ������࣬�����ֽл���

// �����̳� �Ѹ�������Ա�Ϊ�Լ������� ����ı����Ե�����
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
		// left(); // �޷�����
	}

};

// �����̳�
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
		// left(); // �޷�����
	}
};
// ˽�м̳�
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
		// left(); // �޷�����
	}
};

class Cpp2 : public Cpp {
	void test() {
		//public_header(); // �����˽������
		//protected_footer(); // �����˽������
	}
};

void extendTest01() {
	cout << "_______java_______" << endl;
	Java ja;
	ja.public_header();
	// ja.protected_footer(); // �޷������ˣ��Ѿ�������Լ�protected����
	// ja.private_left(); // ����˽������ �޷�����
	ja.content();

	cout << "_______python_______" << endl;
	Python py;
	// py.public_header(); // �޷������ˣ��Ѿ�������Լ�protected����
	// py.protected_footer(); // �޷������ˣ��Ѿ�������Լ�protected����
	// py.private_left(); // ����˽������ �޷�����
	py.content();
	cout << "_______cpp_______" << endl;
	Cpp cp;
	// cp.public_header(); // �޷������ˣ��Ѿ�������Լ�priavte����
	// cp.protected_footer(); // �޷������ˣ��Ѿ�������Լ�priavte����
	// cp.private_left(); // ����˽������ �޷�����
	cp.content();
}

void extendTest02() {
	Java ja; 
	// 16 ˵�����ĸ����Զ����ˣ�˽��������Ȼ���ʲ���������Ҳ�̳������ˣ�ֻ������������������
	cout <<"sizeof ja = " << sizeof ja << endl; 

	// ���� ͨ��������Ա������ʾ����
	// �����ļ�λ�� ִ�� cl /d1 reportSingleClassLayout���� "�ļ���"
	// �����ļ�λ�� ִ�� cl /d1 reportSingleClassLayoutJava "5.6 �̳�.cpp"
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
	// �̳�
	extendTest01();
	// ��������
	extendTest02();

}