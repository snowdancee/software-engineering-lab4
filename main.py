# coding=UTF-8
import sys
import Maindesign

from PyQt5.QtWidgets import QApplication, QWidget, QMainWindow

if __name__ == '__main__':
    app = QApplication(sys.argv)
    mainWindow = QMainWindow()
    ui = Maindesign.Ui_MainWindow()
    ui.setupUi(mainWindow)
    mainWindow.show()
    sys.exit(app.exec_())
#参考资料https://blog.csdn.net/Newnotes/article/details/105767501
