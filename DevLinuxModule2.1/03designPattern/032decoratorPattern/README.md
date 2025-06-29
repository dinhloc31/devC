# Decorator Pattern C Example

Dự án này minh họa mẫu thiết kế Decorator trong C với ví dụ về quán cà phê. Bạn có thể tạo một loại đồ uống cơ bản và trang trí nó với các thành phần bổ sung như sữa.

## Cấu trúc dự án

decorator-pattern-c
├── inc
│   ├── beverage.h
│   ├── beverageDecorator.h
│   ├── coffee.h
│   └── milkDecorator.h
├── src
│   ├── coffee.c
│   └── milkDecorator.c
├── Makefile
├── main.c
└── README.md

## Hướng dẫn build và chạy

1. **Build dự án**  
   make all

2. **Clean chuong trinh
   make clean

## Tổng quan Decorator Pattern

- `beverage`: Interface định nghĩa các thao tác cơ bản cho đồ uống.
- `coffee`: Cài đặt cụ thể cho đồ uống cà phê.
- `milkDecorator`: Decorator bổ sung chức năng (giá và mô tả) cho đồ uống.

Mẫu thiết kế này giúp mở rộng chức năng cho đối tượng một cách linh hoạt mà không cần sửa đổi mã nguồn gốc.

