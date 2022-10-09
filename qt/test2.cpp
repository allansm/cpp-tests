#include <QClipboard>
#include <QApplication>
#include <iostream>

int main(int argc, char ** argv){
	QApplication app(argc, argv);

	QClipboard *clip = QApplication::clipboard();
	std::cout << clip->text().toStdString();
}
