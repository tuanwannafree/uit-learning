CHƯƠNG 3.
LỚP VÀ ĐỐI TƯỢNG

Giới thiệu
Khai báo lớp
Các thành phần của lớp
Cơ chế tạo lập các lớp
Định nghĩa hàm thành phần
Tạo lập đối tượng
Phạm vi truy xuất
Hàm thiết lập – Constructor
Hàm hủy bỏ – Destructor
Hàm bạn, lớp bạn
Các phương thức Truy vấn, Cập nhật
Thành viên tĩnh – static member
Các nguyên tắc xây dựng lớp

Giới thiệu

Một lớp bao gồm các thành phần dữ liệu (thuộc tính) và các phương thức (hàm thành phần).
Lớp trong C++ thực chất là một kiểu dữ liệu do người sử dụng định nghĩa.
Trong C++, dùng từ khóa class để chỉ điểm bắt đầu của một lớp sẽ được cài đặt.

Lớp đối tượng - class

Lớp là một mô tả trừu tượng của nhóm các đối tượng cùng bản chất, ngược lại mỗi một đối tượng là một thể hiện cụ thể cho những mô tả trừu tượng đó.
Lớp là cái ta thiết kế và lập trình
Đối tượng là cái ta tạo (từ một lớp) tại thời gian chạy.

{1, 5, 7, -3, 8} -> Khái quát hóa -> Số nguyên(int)

Khai báo lớp

class <tên_lớp> 
{
	//Thành phần dữ liệu

	//Thành phần xử lý
};

class <tên_lớp> {
  private:
   <khai báo thành phần riêng trong từng đối tượng>
  protected:
   <khai báo thành phần riêng trong từng đối tượng, có thể truy cập từ lớp dẫn xuất >
  public:
    <khai báo thành phần công cộng>
};

![image](https://github.com/user-attachments/assets/35e241db-52a8-419f-a98e-6f4f98ae14c8)

Các thành phần của lớp
Thuộc tính: Các thuộc tính được khai báo giống như khai báo biến trong C
Phương thức: Các phương thức được khai báo giống như khai báo hàm trong C. Có hai cách định nghĩa thi hành của một phương thức
Định nghĩa thi hành trong lớp
Định nghĩa thi hành ngoài lớp

Cơ chế tạo lập các lớp
Xác định các thuộc tính (dữ liệu)
Những gì mà ta biết về đối tượng – giống như một struct
Xác định các phương thức (hình vi)
Những gì mà đối tượng có thể làm
Xác định các quyền truy xuất
Sẽ trình bày sau

Định nghĩa hàm thành phần
Định nghĩa các hàm thành phần ở bên ngoài khai báo lớp:
<tên kiểu giá trị trả về> <tên lớp>::<tên hàm> (<danh sách tham số>) 
{
	<nội dung >
}
Ví dụ:
void point::display() { 
		//……..
}
![image](https://github.com/user-attachments/assets/b826be98-83f3-4f19-ba12-01dca2a2251e)

Tạo lập đối tượng
Khai báo và tạo đối tượng:
<tên lớp>  <tên đối tượng>;
Gọi hàm thành phần của lớp 
<tên đối tượng>.<tên hàm thành phần> (<danh sách các tham số nếu có>);
<tên con trỏ đối tượng>🡪<tên hàm thành phần> (<danh sách các tham số nếu có>);

Class Time Specification
class  Time {
  public: 				
	void Set (int  hours , int  minutes , int  seconds);
	void	 Increment ( );
	void	 Write ( )  const;
	Time (int  initHrs, int  initMins,  int  initSecs ); //constructor 
	Time ( ); 			                      //default constructor
  private:
	int             hrs;       
	int             mins;
	int	         secs;
} ;

![image](https://github.com/user-attachments/assets/27a8d7c7-0642-4a92-82f7-1d478d00f51c)
![image](https://github.com/user-attachments/assets/0983431c-35ff-42ec-ac5d-ca8977621253)
![image](https://github.com/user-attachments/assets/9eab62f8-5079-4976-bfbf-a8ba63c41ca5)

ví dụ 
Xây dựng lớp Điểm (Point) trong hình học 2D
Thuộc tính
Tung độ
Hoành độ
Thao tác (phương thức)
Khởi tạo
Di chuyển
In ra màn hình
…

/*point.cpp*/
#include <iostream.h>
#include <conio.h>
class point {
  		/*khai báo các thành phần dữ  liệu riêng*/
  		private:
    			int x,y;
 		 /*khai báo các hàm thành phần công cộng*/
  		public: 
    			void init(int ox, int oy);
    			void move(int dx, int dy);
    			void display();
    };

void point::init(int ox, int oy) {
  	cout<<"Ham thanh phan init\n";
     x = ox; y = oy; 
	/*x,y là các thành phần của đối tượng gọi hàm thành phần*/
  }
void point::move(int dx, int dy) {
  	cout<<"Ham thanh phan move\n";
 	 x += dx; y += dy;
  }
void point::display() {
  	cout<<"Ham thanh phan display\n";
  	cout<<"Toa do: "<<x<<" "<<y<<"\n";
  }

void main() {
  	point p;
  	p.init(2,4); /*gọi hàm thành phần từ đối tượng*/
  	p.display();
  	p.move(1,2);
  	p.display();
  }

output
Ham thanh phan init
Ham thanh phan display
Toa do: 2 4
Ham thanh phan move
Ham thanh phan display
Toa do: 3 6

Phạm vi truy xuất
Trong định nghĩa của lớp ta có thể xác định khả năng truy xuất thành phần của một lớp nào đó từ bên ngoài phạm vi lớp.
private, protected và public là các từ khoá xác định phạm vi truy xuất
Mọi thành phần được liệt kê trong phần public đều có thể truy xuất trong bất kỳ hàm nào.
Những thành phần được liệt kê trong phần private chỉ được truy xuất bên trong phạm vi lớp.
Trong lớp có thể có nhiều nhãn private và public
Mỗi nhãn này có phạm vi ảnh hưởng cho đến khi gặp một nhãn kế tiếp hoặc hết khai báo lớp.
Nhãn private đầu tiên có thể bỏ qua vì C++ ngầm hiểu rằng các thành phần trước nhãn public đầu tiên là private.

Ví dụ
class TamGiac{
  private:
    float a,b,c;/*độ dài ba cạnh*/
  public:
    void Nhap();/*nhập vào độ dài ba cạnh*/
    void In();/*in ra các thông tin liên quan đến tam giác*/
  private:
    int Loaitg();//cho biết kiểu của tam giác: 1-d,2-vc,3-c,4-v,5-t
    float DienTich();/*tính diện tích của tam giác*/
  };

class TamGiac{
  private:
    float a,b,c;/*độ dài ba cạnh*/
    int Loaitg();//cho biết kiểu của tam giác: 1-d,2-vc,3-c,4-v,5-t
    float DienTich();/*tính diện tích của tam giác*/
  public:
    void Nhap();/*nhập vào độ dài ba cạnh*/
    void In();/*in ra các thông tin liên quan đến tam giác*/
};

void point::init (int xx, int yy){
	x = xx;
	y = yy;  //x, y la thanh phan cua lop point
}
Hàm thành phần có quyền truy nhập đến các thành phần private của đối tượng gọi nó

Con trỏ this
Từ khoá this trong định nghĩa của các hàm thành phần lớp dùng để xác định địa chỉ của đối tượng dùng làm tham số ngầm định cho hàm thành phần.
Con trỏ this tham chiếu đến đối tượng đang gọi hàm thành phần.
Ví dụ:
	int Trung(point pt){
		return (this 🡪 x == pt.x && this 🡪 y == pt.y);
	}

int Trung (point pt){ // So sánh hai đối tượng bằng cách truyền tham trị (giá trị được sao chép).
	return (x==pt.x && y==pt.y);
}
int Trung (point *pt){ // So sánh bằng cách truyền con trỏ (truy cập thông qua ->).
	return (x==pt🡪x && y==pt🡪y); 
}
int Trung (point &pt) {  //  So sánh bằng cách truyền tham chiếu (tránh sao chép dữ liệu).
	return (x==pt.x && y==pt.y); 
}
Hàm thành phần có quyền truy cập đến tất cả các thành phần private của các đối tượng, tham chiếu đối tượng hay con trỏ đối tượng có cùng kiểu lớp khi được dùng là tham số hình thức của nó.

Con trỏ this
Từ khoá this trong định nghĩa của các hàm thành phần lớp dùng để xác định địa chỉ của đối tượng dùng làm tham số ngầm định cho hàm thành phần.
Con trỏ this tham chiếu đến đối tượng đang gọi hàm thành phần.
Ví dụ:
	int Trung(point pt){
		return (this 🡪 x == pt.x && this 🡪 y == pt.y);
	}
 
Phép gán đối tượng
Là việc sao chép giá trị các thành phần dữ liệu từ đối tượng a sang đối tượng b tương ứng từng đôi một
Ví dụ:
point a, b;
a.init(5,2);
b = a;

Hàm thiết lập – Constructor
Trong hầu hết các thuật giải, để giải quyết một vấn đề 🡪thường phải thực hiện các công việc:
Khởi tạo giá trị cho biến, cấp phát vùng bộ nhớ của biến con trỏ, mở tập tin để truy cập,…
Hoặc khi kết thúc, chúng ta phải thực hiện quá trình ngược lại như: Thu hồi vùng bộ nhớ đã cấp phát, đóng tập tin,…
Các ngôn ngữ OOP có các phương thức để thực hiện công việc này một cách “tự động” gọi là phương thức thiết lập và phương thức hủy bỏ.

Constructor là một loại phương thức đặc biệt dùng để khởi tạo thể hiện của lớp.
Bất kỳ một đối tượng nào được khai báo đều phải sử dụng một hàm thiết lập để khởi tạo các giá trị thành phần của đối tượng.
Hàm thiết lập được khai báo giống như một phương thức với tên phương thức trùng với tên lớp và không có giá trị trả về (kể cả void).
Constructor phải có thuộc tính public

Constructor có thể được khai báo chồng như các hàm C++ thông thường khác hay không?
Constructor có thể được khai báo chồng như các hàm C++ thông thường khác

Constructor có thể được khai báo với các tham số có giá trị ngầm định hay không?
Constructor có thể được khai báo với các tham số có giá trị ngầm định
Có thể có nhiều hàm thiết lập trong một lớp (chồng hàm)

Ví dụ
class point{
  	/*Khai báo các thành phần dữ liệu*/
 	int x, y;
	public:
  		point() { x = 0; y = 0; }  /*Hàm thiết lập mặc định*/
  		point(int ox, int oy) { x = ox; y = oy; }/*Hàm thiết lập*/
  		void move (int dx, int dy);
  		void display();
};
point a(5,2);
point b;
point c(3); ?

class point{
  	/*Khai báo các thành phần dữ liệu*/
 	int x, y;
	public:
  		point() { x = 0; y = 0; }  /*Hàm thiết lập mặc định*/
  		point(int ox, int oy) { x = ox; y = oy; }/*Hàm thiết lập*/
  		void move (int dx, int dy);
  		void display();
};
point a(5,2);
point b;
point c(3); ?

Constructor mặc định
Constructor mặc định (default constructor) là constructor được gọi khi thể hiện được khai báo mà không có đối số nào được cung cấp
MyClass x;
MyClass* p = new MyClass;
Ngược lại, nếu tham số được cung cấp tại khai báo thể hiện, trình biên dịch sẽ gọi constructor khác (overload)
MyClass x(5);
MyClass* p = new MyClass(5);
Đối với constructor mặc định, nếu ta không cung cấp bất kỳ constructor nào, C++ sẽ tự sinh constructor mặc định là một phương thức rỗng.
Tuy nhiên, nếu ta không định nghĩa constructor mặc định nhưng lại có các constructor khác, trình biên dịch sẽ báo lỗi không tìm thấy constructor mặc định nếu ta không cung cấp tham số khi tạo thể hiện.

Ví dụ
class point{
  	/*Khai báo các thành phần dữ liệu*/
 	int x, y;
	public:
  		point(int ox, int oy = 1){ x = ox; y = oy;}
  		void move (int dx, int dy);
  		void display();
};
point a(5,2);
point b;
point c(3);

Constructor mặc định

Constructor mặc định (default constructor) là constructor được gọi khi thể hiện được khai báo mà không có đối số nào được cung cấp
MyClass x;
MyClass* p = new MyClass;
Ngược lại, nếu tham số được cung cấp tại khai báo thể hiện, trình biên dịch sẽ gọi constructor khác (overload)
MyClass x(5);
MyClass* p = new MyClass(5);

Đối với constructor mặc định, nếu ta không cung cấp bất kỳ constructor nào, C++ sẽ tự sinh constructor mặc định là một phương thức rỗng.
Tuy nhiên, nếu ta không định nghĩa constructor mặc định nhưng lại có các constructor khác, trình biên dịch sẽ báo lỗi không tìm thấy constructor mặc định nếu ta không cung cấp tham số khi tạo thể hiện.

Ví dụ
class point{
  	/*Khai báo các thành phần dữ liệu*/
 	int x, y;
	public:
  		point(int ox, int oy = 1){ x = ox; y = oy;}
  		void move (int dx, int dy);
  		void display();
};
point a(5,2);
point b;
point c(3);

Copy constructor
Chúng ta có thể tạo đối tượng mới giống đối tượng cũ một số đặc điểm, không phải hoàn toàn như phép gán bình thường, hình thức “giống nhau” được định nghĩa theo quan niệm của người lập trình. Để làm được vấn đề này, trong các ngôn ngữ OOP cho phép ta xây dựng phương thức thiết lập sao chép.
Đây là phương thức thiết lập có tham số là tham chiếu đến đối tượng thuộc chính lớp này.
Trong phương thức thiết lập sao chép có thể ta chỉ sử dụng một số thành phần nào đó của đối tượng ta tham chiếu 🡪“gần giống nhau”
(Trong quá trình lập trình, chúng ta hoàn toàn có thể gán một đối tượng cho một đối tượng khác thuộc cùng lớp, khi đó 2 đối tượng sẽ hoàn toàn giống nhau về giá trị (tất cả các byte).)

![image](https://github.com/user-attachments/assets/84dc5b84-04b0-4c22-9a05-fb8113e1e60a)
Trong quá trình lập trình, chúng ta hoàn toàn có thể gán một đối tượng cho một đối tượng khác thuộc cùng lớp, khi đó 2 đối tượng sẽ hoàn toàn giống nhau về giá trị (tất cả các byte).
Chúng ta cũng có thể tạo đối tượng mới giống đối tượng cũ một số đặc điểm, không phải hoàn toàn như phép gán bình thường, hình thức “giống nhau” được định nghĩa theo quan niệm của người lập trình. Để làm được vấn đề này, trong các ngôn ngữ LTHDT cho phép ta xây dựng phương thức thiết lập sao chép.
Đây là phương thức thiết lập có tham số là tham chiếu đến đối tượng thuộc chính lớp này.
Trong phương thức thiết lập sao chép có thể ta chỉ sử dụng một số thành phần nào đó của đối tượng ta tham chiếu 🡪 “gần giống nhau”

Hàm hủy bỏ – Destructor
Destructor, được gọi ngay trước khi một đối tượng bị thu hồi.
Destructor thường được dùng để thực hiện việc dọn dẹp cần thiết trước khi một đối tượng bị hủy.
Một lớp chỉ có duy nhất một Destructor
Phương thức Destructor trùng tên với tên lớp nhưng có dấu ~ đặt trước
Được tự động gọi thực hiện khi đối tượng hết phạm vi sử dụng.
Destructor phải có thuộc tính public
(Tương tự như phương thức constructor – được gọi khi một đối tượng được tạo. Destructor – được gọi ngay trước khi một đối tượng bị thu 
hồi.
Destructor không có giá trị trả về.)

Ví dụ
class vector{
	int n;  	//số chiều
	float *v;   	//vùng nhớ tọa độ
public:
	vector(); 	//Hàm thiết lập không tham số
	vector(int size); //Hàm thiết lập một tham số
	vector(int size, float *a);
	~vector();	//Hàm hủy bỏ, luôn luôn không có tham số
	void display();
};

Hàm bạn, lớp bạn
Giả sử có lớp Vector, lớp Matrix
Cần viết hàm nhân Vector với một Matrix
Hàm nhân:
Không thể thuộc lớp Vector
Không thể thuộc lớp Matrix
Không thể tự do
🡪Giải pháp: Xây dựng hàm truy cập dữ liệu?

Hàm bạn không thuộc lớp. Tuy nhiên, có quyền truy cập các thành viên private của lớp.
Khi định nghĩa một lớp, có thể khai báo một hay nhiều hàm “bạn” (bên ngoài lớp) 
Ưu điểm:
Kiểm soát các truy nhập ở cấp độ lớp – không thể áp đặt hàm bạn cho lớp nếu điều đó không được dự trù trước trong khai báo của lớp.

Dùng từ khóa friend để khai báo, định nghĩa hàm bạn
Đây là cách cho phép chia sẻ dữ liệu giữa các đối tượng với một hàm tùy ý trong chương trình (hàm friend) hoặc chia sẻ các thành phần của đối tượng có thuộc tính private hay protected với các đối tượng khác (lớp friend).
(Chúng ta đã biết trong phần phạm vi truy cập, khi một thành phần mang thuộc tính là privte hoặc protected thì các hàm bên ngoài lớp (hàm có chứa đối tượng thuộc lớp) ko thể truy cập đến thành phần này. Khi một hàm mang thuộc tính friend cho phép chúng ta coi hàm này như là bạn của lớp, và đương nhiên đã là bạn bè cũng nên có một chút ưu đãi khi “bước vào nhà”)
Các tính chất của quan hệ friend:
Phải được cho, không được nhận
Lớp B là bạn của lớp A, lớp A phải khai báo rõ ràng B là bạn của nó
Không đối xứng, Không bắc cầu
Quan hệ friend có vẻ như vi phạm khái niệm đóng gói (encapsulation) của OOP nhưng có khi lại cần đến nó để cài đặt các mối quan hệ giữa các lớp và khả năng đa năng hóa toán tử trên lớp (sẽ đề cập ở chương sau)

Ví dụ
class COUNTERCLASS{
	int Counter;
public:
	char CounterChar;
	void Init( char );
	void AddOne( ){
		Counter++;
	}
	friend int Total (int);
};

COUNTERCLASS MyCounter[26];  	//Có 26 đối tượng
int Total(int NumberObjects)
{
	for (int i=0, sum=0; i<NumberObjects; i++)
		sum += MyCounter[i].Counter
		//Tính tổng số ký tự trong số các Objects ký tự
	return sum;
}

(Chúng ta thấy hàm Total(…) không phải là một phương thức của lớp COUNTERCLASS, nhưng nó có thể truy cập đến dữ liệu Counter của lớp này, bởi Total(…) được mô tả là friend của lớp COUNTERCLASS)

Lưu ý:
Vị trí của khai báo “bạn bè” trong lớp hoàn toàn tùy ý
Trong hàm bạn, không còn tham số ngầm định this như trong hàm thành phần
Hàm bạn của một lớp có thể có một hay nhiều tham số, hoặc có thể có giá trị trả về thuộc kiểu lớp đó

Một lớp có thể truy cập đến các thành phần có thuộc tính private của một lớp khác.
Để thực hiện được điều này, chúng ta có thể lấy toàn bộ một lớp làm bạn (lớp friend) cho lớp khác.
Một lớp có thể truy cập đến các thành phần có thuộc tính private của một lớp khác.
Để thực hiện được điều này, chúng ta có thể lấy toàn bộ một lớp làm bạn (lớp friend) cho lớp khác.

Ví dụ
class TOM{
public:
	friend class JERRY; 	//Có lớp bạn là JERRY
private:
	int SecretTom;		//Bí mật của TOM
};
class JERRY{
public:
	void Change(TOM T){
		T.SecretTom++; 	//Bạn nên có thể truy cập
	}
};

Thao tác với dữ liệu private
Khi muốn truy xuất dữ liệu private từ các đối tượng thì phải làm thế nào?

Khi muốn cập nhật dữ liệu private từ các đối tượng thì phải làm thế nào?
Các phương thức truy vấn (query method) là các phương thức dùng để hỏi về giá trị của các thành viên dữ liệu của một đối tượng
Khi muốn truy xuất dữ liệu private từ các đối tượng thì phải làm thế nào?

Phương thức Truy vấn
Có nhiều loại câu hỏi truy vấn có thể:
Truy vấn đơn giản (“giá trị của x là bao nhiêu?”)
Truy vấn điều kiện (“thành viên x có > 10 không?”)
Truy vấn dẫn xuất (“tổng giá trị của các thành viên x và y là bao nhiêu?”)
Đặc điểm quan trọng của phương thức truy vấn là nó không nên thay đổi trạng thái hiện tại của đối tượng

Đối với các truy vấn đơn giản, quy ước đặt tên phương thức như sau: Tiền tố “get”, tiếp theo là tên của thành viên cần truy vấn
int getX();
int getSize();
Các loại truy vấn khác nên có tên có tính mô tả
Truy vấn điều kiện nên có tiền tố “is”

Phương thức Cập nhật

Thường để thay đổi trạng thái của đối tượng bằng cách sửa đổi một hoặc nhiều thành viên dữ liệu của đối tượng đó.
Dạng đơn giản nhất là gán một giá trị nào đó cho một thành viên dữ liệu.
Đối với dạng cập nhật đơn giản, quy ước đặt tên như sau: Dùng tiền tố “set” kèm theo tên thành viên cần sửa
int setX(int);

Truy vấn và Cập nhật
**Nếu phương thức get/set chỉ có nhiệm vụ cho ta đọc/ghi giá trị cho các thành viên dữ liệu 🡪Quy định các thành viên private để được ích lợi gì?
Ngoài việc bảo vệ các nguyên tắc đóng gói, ta cần kiểm tra xem giá trị mới cho thành viên dữ liệu có hợp lệ hay không.
Sử dụng phương thức truy vấn cho phép ta thực hiện việc kiểm tra trước khi thực sự thay đổi giá trị của thành viên.
Chỉ cho phép các dữ liệu có thể truy vấn hay thay đổi mới được truy cập đến.

Ví dụ

int Student::setGPA (double newGPA){
	if ((newGPA >= 0.0) && (newGPA <= 4.0)){
		this->gpa = newGPA;
		return 0; // Return 0 to indicate success
	}
	else
	{
		return -1; // Return -1 to indicate failure
	}
}

Thành viên tĩnh – static member
Trong C, static xuất hiện trước dữ liệu được khai báo trong một hàm nào đó thì giá trị của dữ liệu đó vẫn được lưu lại như một biến toàn cục.
Trong C++, nếu static xuất hiện trước một dữ liệu hoặc một phương thức của lớp thì giá trị của nó vẫn được lưu lại và có ý nghĩa cho đối tượng khác của cùng lớp này.
Các thành viên static có thể là public, private hoặc protected.
![image](https://github.com/user-attachments/assets/0fab0a0e-4326-4aad-bb26-8268e62fa92e)

Ví dụ
Đếm số đối tượng MyClass:
class MyClass{
	public:
		MyClass();
		~MyClass();
		void printCount();
	private:
		static int count;
};

int MyClass::count = 0;
MyClass::MyClass(){
	this 🡪 count++;
}
MyClass::~MyClass(){
	this 🡪 count--;
}
void MyClass::printCount(){
	cout << “There are currently ” << this 🡪 count << “ instance(s) of MyClass.\n”;
}

void main()
{
	MyClass* x = new MyClass;
	x 🡪 printCount();
	MyClass* y = new MyClass;
	 x 🡪 printCount();
	 y 🡪 printCount();
	delete x;
	 y 🡪 printCount();
}

Thành viên tĩnh – static member
Phương thức static?
Đối với các phương thức static, ngoài ý nghĩa tương tự với dữ liệu, còn có sự khác biệt cơ bản đó là việc cho phép truy cập đến các phương thức static khi chưa khai báo đối tượng (thông qua tên lớp)
(Phương thức tĩnh hoạt động ít nhiều giống như phương thức toàn cục, ta truy cập phương thức này mà không cần phải tạo bất cứ thể hiện hay đối tượng của lớp chứa phương thức toàn cục. Tuy nhiên, lợi ích của phương thức tĩnh vượt xa phương thức toàn cục vì phương thức tĩnh được bao bọc trong phạm vi của một lớp nơi nó được định nghĩa, do vậy ta sẽ không gặp tình trạng lộn xộn giữa các phương thức trùng tên do chúng được đặt trong namespace.)

Các thành viên lớp tĩnh public có thể được truy cập thông qua bất kỳ đối tượng nào của lớp đó, hoặc chúng có thể được truy cập thông qua tên lớp sử dụng toán tử định phạm vi.
Các thành viên lớp tĩnh private và protected phải được truy cập thông qua các hàm thành viên public của lớp hoặc thông qua các friend của lớp.
Các thành viên lớp tĩnh tồn tại ngay cả khi đối tượng của lớp đó không tồn tại.

Để truy cập một thành viên lớp tĩnh public khi các đối tượng của lớp không tồn tại, đơn giản thêm vào đầu tên lớp và toán tử định phạm vi cho thành viên dữ liệu.
Để truy cập một thành viên lớp tĩnh private hoặc protected khi các đối tượng của lớp không tồn tại, một hàm thành viên public phải được cung cấp và hàm phải được gọi bởi thêm vào đầu tên của nó với tên lớp và toán tử định phạm vi. 
Ví dụ
class HinhTron
{
double r;
static double PI;
public:
HinhTron(void);
double Area();
static double getPI();
~HinhTron(void);
};

void main()
{
cout<<"PI = "<<HinhTron::getPI()<<endl;
HinhTron h1, h2;
cout<<"h1.PI = "<<h1.getPI()<<endl;
cout<<"h2.PI = "<<h1.getPI()<<endl;
}

Ví dụ về đối tượng toàn cục
Xét đoạn chương trình sau:
	#include <iostream.h>
	void main(){
	    cout << "Hello, world.\n";
	}
Hãy sửa lại đoạn chương trình trên để có kết xuất:
Entering a C++ program saying...
Hello, world.
And then exitting…
Yêu cầu không thay đổi hàm main() dưới bất kỳ hình thức nào.

#include <iostream.h>
class Dummy{
public:
   Dummy(){cout << "Entering a C++ program saying...\n";}
   ~Dummy(){cout << "And then exitting...";}
};
Dummy A;
void main(){
    cout << "Hello, world.\n";
}

Đối tượng là thành phần của lớp

class Diem{
	double x, y;
public:
	Diem (double xx, double yy) { x = xx; y = yy; }
	// ...
};
class TamGiac{
	Diem A, B, C;
public:
	void Ve( );
	// ...
};
TamGiac t; 	//Error ?
Diem D;	//Error ?

error C2512: 'TamGiac' : no appropriate default constructor available
error C2512: 'Diem' : no appropriate default constructor available

Đối tượng có thể là thành phần của đối tượng khác, khi một đối tượng thuộc lớp “lớn” được tạo ra, các thành phần của nó cũng được tạo ra.
Phương thức thiết lập (nếu có) sẽ được tự động gọi cho các đối tượng thành phần.
Khi đối tượng kết hợp bị hủy 🡪 đối tượng thành phần của nó cũng bị hủy, nghĩa là phương thức hủy bỏ sẽ được gọi cho các đối tượng thành phần, sau khi phương thức hủy bỏ của đối tượng kết hợp được gọi.

Nếu đối tượng thành phần phải cung cấp tham số khi thiết lập thì đối tượng kết hợp (đối tượng lớn) phải có phương thức thiết lập để cung cấp tham số thiết lập cho các đối tượng thành phần.

Cú pháp để khởi động đối tượng thành phần là dùng dấu hai chấm (:) theo sau bởi tên thành phần và tham số khởi động.


Ví dụ

class TamGiac{
	Diem A, B, C;
public:
	TamGiac(double xA, double yA, double xB, double yB, double xC, double yC) : A(xA,yA), B(xB,yB),C(xC,yC){
	}
	void Ve();
	// ...
};
TamGiac t(100,100,200,400,300,300);


![image](https://github.com/user-attachments/assets/68827e5c-1c38-471a-aa74-974cd0955fc2)

Ví dụ
class Diem{
	double x,y;
public:
	Diem(double xx = 0, double yy = 0) : x(xx), y(yy){
	}
	void Set(double xx, double yy){
		x = xx;
		y = yy;
	}
};
Đoạn chương trình trên đúng hay sai? 🡪 Đúng

Đối tượng là thành phần của mảng
Khi một mảng được tạo ra 🡪các phần tử của nó cũng được tạo ra 🡪phương thức thiết lập sẽ được gọi cho từng phần tử.
Vì không thể cung cấp tham số khởi động cho tất cả các phần tử của mảng 🡪khi khai báo mảng, mỗi đối tượng trong mảng phải có khả năng tự khởi động, nghĩa là có thể thiết lập không cần tham số.

Đối tượng có khả năng tự khởi động trong những trường hợp nào?
Lớp không có phương thức thiết lập
Lớp có phương thức thiết lập không tham số
Lớp có phương thức thiết lập mà mọi tham số đều có giá trị mặc nhiên

class Diem
{
	double x,y;
	public:
		Diem(double xx, double yy) : x(xx), y(yy) { }
		void Set(double xx, double yy) {
			x = xx, y = yy;
		}
		// ...
};

class String {
	char *p;
public:
	String(char *s) { p = strdup(s); }
	String(const String &s) { p = strdup(s.p); }
	~String() {
	   	cout << "delete "<< (void *)p << "\n"; 
      	delete [] p;
	}
};


![image](https://github.com/user-attachments/assets/e4159fec-dde1-4c1f-a96e-676b7889e755)

Dùng phương thức thiết lập
với tham số có giá trị mặc nhiên
class Diem
{
	double x,y;
public:
	Diem(double xx = 0, double yy = 0) : x(xx), y(yy) { }
	void Set(double xx, double yy) {
		x = xx, y = yy;
	}
	// ...
};
class String{
	char *p;
public:
	String(char *s = "") { p = strdup(s); }
	String(const String &s) { p = strdup(s.p); }
	~String() {
		cout << "delete "<< (void *)p << "\n"; 
		delete [] p;
	}
};


![image](https://github.com/user-attachments/assets/685af301-341e-4187-b8c7-9c7b4062cc59)

Dùng phương thức thiết lập 
không tham số
class Diem
{
	double x,y;
public:
	Diem(double xx, double yy) : x(xx), y(yy)
	{ }
	Diem() : x(0), y(0)
	{ }
	// ...
};
class String{
	char *p;
public:
	String(char *s) { p = strdup(s); }
	String() { p = strdup(“”); }
	~String() { 
		cout << "delete "<< (void *)p << "\n"; 
		delete [] p;
	}
};

![image](https://github.com/user-attachments/assets/cda91bcd-4b5e-4dff-8204-ba256167267a)

Đối tượng được cấp phát động
Đối tượng được cấp phát động là các đối tượng được tạo ra bằng phép toán new và bị hủy đi bằng phép toán delete

Phép toán new cấp đối tượng trong vùng heap và gọi phương thức thiết lập cho đối tượng được cấp.
(Phép toán new cấp đối tượng trong vùng heap (hay vùng free store) và gọi phương thức thiết lập cho đối tượng được cấp.
Dùng new và delete cũng có thể cấp nhiều đối tượng và hủy nhiều đối tượng.)

Đối tượng được cấp phát động
class String {
    char *p;
public:
    String( char *s ) { p = strdup(s); }
    String( const String &s ) { p = strdup(s.p); }
    ~String() { delete [] p; }
    //...
};
class Diem {
    double x,y;
public:
    Diem(double xx, double yy) : x(xx), y(yy) {  }
    //...
};

Đối tượng được cấp phát động
class String {
    char *p;
public:
    String( char *s ) { p = strdup(s); }
    String( const String &s ) { p = strdup(s.p); }
    ~String() { delete [] p; }
    //...
};
class Diem {
    double x,y;
public:
    Diem(double xx, double yy) : x(xx), y(yy) {  }
    //...
};


![image](https://github.com/user-attachments/assets/f4da93cd-7356-4d48-aae0-bad1a05ffb54)


![image](https://github.com/user-attachments/assets/c7e85afb-229c-449e-a5d6-58bfaed31f0b)

![image](https://github.com/user-attachments/assets/ecee8735-4839-4f1d-ac57-0c6b6810b37a)


![image](https://github.com/user-attachments/assets/6299ce50-0e2a-4b70-bdb7-6d7e8ff8ed6e)


![image](https://github.com/user-attachments/assets/29165aa8-e0c3-4528-ad96-8f50db5e1a4b)


![image](https://github.com/user-attachments/assets/ba26d1a2-71d4-4cc8-baa3-e94b95662692)


![image](https://github.com/user-attachments/assets/37ef0e00-9e39-4bb9-b183-e68abe5fbf64)


![image](https://github.com/user-attachments/assets/437c17c1-efb2-48ba-bcca-721287e3e4bd)


![image](https://github.com/user-attachments/assets/61b26357-d938-40bf-b8bd-6ee8930fdd3a)


![image](https://github.com/user-attachments/assets/b1ea232e-bcf0-4ec8-8b6f-77059c33d84a)


![image](https://github.com/user-attachments/assets/1e7bd74b-b945-4d9d-956c-0555f832b83b)


![image](https://github.com/user-attachments/assets/1677faec-5365-49da-a9a5-c70df3bff354)


![image](https://github.com/user-attachments/assets/a43b7ea9-3212-41fe-b099-b1e6c5e6b54a)


![image](https://github.com/user-attachments/assets/f75c0c17-a4d4-474e-b970-053bb23a4f89)


![image](https://github.com/user-attachments/assets/92f24338-9c64-4ec8-91fd-8a7f9bada42d)


![image](https://github.com/user-attachments/assets/ff7a7f0a-1bea-4bba-bf34-ea8300602242)
