#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "filemanager.cpp"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //     explicit QListWidgetItem(const QString &text, QListWidget *listview = nullptr, int type = Type);
    ui->setupUi(this);
    //ui->ModuleList->addItems();
    std::string modules = FileManager::Initialize();
    std::stringstream moduleStrean(modules);
    std::string module;
    while (std::getline(moduleStrean, module, '\n')) {
        if(module != " ")
            ui->ModuleList->addItem(new QListWidgetItem(QString::fromStdString(module), ui->ModuleList));
    }

    std::string path = "Takoboto.txt";

    std::vector<Word> words = FileManager::LoadFile(path,'\t');
    std::vector<Word> filtered;
    std::copy_if(words.begin(), words.end(), std::back_inserter(filtered), [](Word i) { return i.word_group & (1 << I_ADJ); });
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_ModuleList_itemDoubleClicked(QListWidgetItem *item)
{
    if(item->text() == "Matching")
        int i = 4;
}







