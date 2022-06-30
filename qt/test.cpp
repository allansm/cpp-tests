#include <QApplication>
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QObject>

#include <iostream>

QLineEdit* input;

int main(int argc, char *argv[]) {
    	QApplication app(argc, argv);

    	QWidget window;

    	input = new QLineEdit(&window);
	input->setGeometry(10,30,150,25);
	
	QPushButton button("Show", &window);
	button.setGeometry(170,30, 70, 25);
    	
	QLabel label("Name:", &window);
	label.setGeometry(10, 10, 50, 15);
	
	QObject::connect(&button, &QPushButton::clicked, &window, [](){
		std::cout << input->text().toStdString() << "\n";
		input->setText("");
	});

	window.resize(250, 65);
    	window.setMaximumSize({250,60});
	window.setWindowTitle("Test");
    	
	window.show();

	return app.exec();
}
