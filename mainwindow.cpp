#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include "QString"
#include "QLabel"
#include "QTextEdit"
#include "QFileDialog"
#include "QTextStream"
#include "QVector"
#include "QMap"
#include "QPair"
#include <sstream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->textEdit->setReadOnly(true);
    ui->textEdit_2->setReadOnly(true);
    ui->lineEdit->setToolTip("Последовательный ввод без пробелов. Пример: abcd");
    ui->lineEdit_2->setToolTip("Последовательный ввод без пробелов. Пример: ad");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString al, substring, symbol[26] = {"S", "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "T", "U", "V", "W", "X", "Y", "Z"};
    QString str, str1, parent, parent_b, parent_a;
    int multiplicity = 0, start_range = 0, end_range = 0, count_of_non_terminal = 0, temp = 1, int_symbol = 0, index = 0;
    QVector<QString> pre_chains, chains;
    QVector<QPair<QString, QString>> full_chains;
    QPair<QString,QString> pair;
    bool check = false;

    al = ui->lineEdit->text();
    substring = ui->lineEdit_2->text();
    multiplicity = ui->comboBox->currentIndex();
    start_range = ui->comboBox_2->currentIndex() + 1;
    end_range = ui->comboBox_3->currentIndex() + 1;

    if(al.size() == 0)
    {
        QMessageBox::warning(this, "Ошибка", "Алфавит пуст");
    }
    else
    {
        if(multiplicity == 0)
            multiplicity = 1;

        QString *ll_rules = new QString [multiplicity * 2];
        QString *pl_rules = new QString [multiplicity * 2];

        if(multiplicity > 1)
        {
            count_of_non_terminal = multiplicity * 2;

            ll_rules[0] = "S -> ";
            pl_rules[0] = "S -> ";
            for(int i = 0; i < al.length(); i++)
            {
                ll_rules[0] = ll_rules[0] + symbol[temp] + al[i] + "|";
                pl_rules[0] = pl_rules[0] + al[i] + symbol[temp] + "|";
            }
            int_symbol = count_of_non_terminal - multiplicity + substring.length();
            while(int_symbol > count_of_non_terminal - 1)
            {
                    int_symbol -= multiplicity;
            }
            ll_rules[0] = ll_rules[0] + symbol[int_symbol] + substring;
            pl_rules[0] = pl_rules[0] + substring + symbol[int_symbol];

            for(int i = 1; i < multiplicity - 1; i++)
            {
                int_symbol++;
                ll_rules[i] = symbol[temp] + " -> ";
                pl_rules[i] = symbol[temp] + " -> ";
                temp++;
                for(int j = 0; j < al.length(); j++)
                {
                    ll_rules[i] = ll_rules[i] + symbol[temp] + al[j] + "|";
                    pl_rules[i] = pl_rules[i] + al[j] + symbol[temp] + "|";
                }
                while(int_symbol > count_of_non_terminal - 1)
                {
                        int_symbol -= multiplicity;
                }
                ll_rules[i] = ll_rules[i] + symbol[int_symbol] + substring;
                pl_rules[i] = pl_rules[i] + substring + symbol[int_symbol];
            }

            ll_rules[multiplicity - 1] = symbol[temp] + " -> ";
            pl_rules[multiplicity - 1] = symbol[temp] + " -> ";
            for(int i = 0; i < al.length(); i++)
            {
                ll_rules[multiplicity - 1] = ll_rules[multiplicity - 1] + "S";
                ll_rules[multiplicity - 1] = ll_rules[multiplicity - 1] + al[i] + "|";
                pl_rules[multiplicity - 1] = pl_rules[multiplicity - 1] + al[i];
                pl_rules[multiplicity - 1] = pl_rules[multiplicity - 1] + "S" + "|";

            }
            int_symbol++;
            while(int_symbol > count_of_non_terminal - 1)
            {
                    int_symbol -= multiplicity;
            }
            ll_rules[multiplicity - 1] = ll_rules[multiplicity - 1] + symbol[int_symbol] + substring;
            pl_rules[multiplicity - 1] = pl_rules[multiplicity - 1] + substring + symbol[int_symbol];

            temp++;
            ll_rules[multiplicity] = symbol[temp] + " -> ";
            pl_rules[multiplicity] = symbol[temp] + " -> ";
            temp++;
            for(int i = 0; i < al.length(); i++)
            {
                ll_rules[multiplicity] = ll_rules[multiplicity] + symbol[temp] + al[i] + "|";
                pl_rules[multiplicity] = pl_rules[multiplicity] + al[i] + symbol[temp] + "|";
            }
            ll_rules[multiplicity] = ll_rules[multiplicity] + QChar(0x3BB);
            pl_rules[multiplicity] = pl_rules[multiplicity] + QChar(0x3BB);

            for(int i = multiplicity + 1; i < count_of_non_terminal - 1; i++)
            {
                ll_rules[i] = symbol[temp] + " -> ";
                pl_rules[i] = symbol[temp] + " -> ";
                temp++;
                for(int j = 0; j < al.length(); j++)
                {
                    ll_rules[i] = ll_rules[i] + symbol[temp] + al[j] + "|";
                    pl_rules[i] = pl_rules[i] + al[j] + symbol[temp] + "|";
                }
                ll_rules[i].remove(ll_rules[i].length() - 1, ll_rules[i].length());
                ll_rules[i].remove(pl_rules[i].length() - 1, pl_rules[i].length());
            }

            ll_rules[count_of_non_terminal - 1] = symbol[temp] + " -> ";
            pl_rules[count_of_non_terminal - 1] = symbol[temp] + " -> ";
            for(int i = 0; i < al.length(); i++)
            {
                ll_rules[count_of_non_terminal - 1] = ll_rules[count_of_non_terminal - 1] + symbol[multiplicity];
                ll_rules[count_of_non_terminal - 1] = ll_rules[count_of_non_terminal - 1] + al[i] + "|";
                pl_rules[count_of_non_terminal - 1] = pl_rules[count_of_non_terminal - 1] + al[i];
                pl_rules[count_of_non_terminal - 1] = pl_rules[count_of_non_terminal - 1] + symbol[multiplicity] + "|";
            }
            ll_rules[count_of_non_terminal - 1].remove(ll_rules[count_of_non_terminal - 1].length() - 1, ll_rules[count_of_non_terminal - 1].length());
            pl_rules[count_of_non_terminal - 1].remove(pl_rules[count_of_non_terminal - 1].length() - 1, pl_rules[count_of_non_terminal - 1].length());

            if(ui->radioButton->isChecked())
            {
                ui->textEdit->setText("");
                QString grammar;
                grammar = "G({";
                for(int i = 0; i < multiplicity * 2; i++)
                {
                    grammar = grammar + symbol[i] + ", ";
                }
                grammar = grammar.left(grammar.size() - 2);
                grammar = grammar + "}, {";
                for(int i = 0; i < al.length(); i++)
                {
                    grammar = grammar + al[i] + ", ";
                }
                grammar = grammar.left(grammar.size() - 2);
                grammar = grammar + "}, P, S)";
                ui->textEdit->append(grammar);
                for(int i = 0; i < multiplicity * 2; i++)
                {
                    ui->textEdit->append(ll_rules[i]);
                }
            }
            else
            {
                ui->textEdit->setText("");
                QString grammar;
                grammar = "G({";
                for(int i = 0; i < multiplicity * 2; i++)
                {
                    grammar = grammar + symbol[i] + ", ";
                }
                grammar = grammar.left(grammar.size() - 2);
                grammar = grammar + "}, {";
                for(int i = 0; i < al.length(); i++)
                {
                    grammar = grammar + al[i] + ", ";
                }
                grammar = grammar.left(grammar.size() - 2);
                grammar = grammar + "}, P, S)";
                ui->textEdit->append(grammar);
                for(int i = 0; i < multiplicity * 2; i++)
                {
                    ui->textEdit->append(pl_rules[i]);
                }
            }
        }

        else
        {
            ll_rules[0] = "S -> ";
            pl_rules[0] = "S -> ";
            for(int i = 0; i < al.length(); i++)
            {
                ll_rules[0] = ll_rules[0] + "S" + al[i] + "|";
                pl_rules[0] = pl_rules[0] + al[i] + "S" + "|";
            }
            ll_rules[0] = ll_rules[0] + "A" + substring;
            pl_rules[0] = pl_rules[0] + substring + "A";

            ll_rules[1] = "A -> ";
            pl_rules[1] = "A -> ";
            for(int i = 0; i < al.length(); i++)
            {
                ll_rules[1] = ll_rules[1] + "A" + al[i] + "|";
                pl_rules[1] = pl_rules[1] + al[i] + "A" + "|";
            }
            ll_rules[1] = ll_rules[1] + QChar(0x3BB);
            pl_rules[1] = pl_rules[1] + QChar(0x3BB);

            if(ui->radioButton->isChecked())
            {
                ui->textEdit->setText("");
                QString grammar;
                grammar = "G = {(";
                for(int i = 0; i < multiplicity * 2; i++)
                {
                    grammar = grammar + symbol[i] + ", ";
                }
                grammar = grammar.left(grammar.size() - 2);
                grammar = grammar + "), (";
                for(int i = 0; i < al.length(); i++)
                {
                    grammar = grammar + al[i] + ", ";
                }
                grammar = grammar.left(grammar.size() - 2);
                grammar = grammar + "), P, S}";
                ui->textEdit->append(grammar);
                for(int i = 0; i < multiplicity * 2; i++)
                {
                    ui->textEdit->append(ll_rules[i]);
                }
            }
            else
            {
                ui->textEdit->setText("");
                QString grammar;
                grammar = "G = {(";
                for(int i = 0; i < multiplicity * 2; i++)
                {
                    grammar = grammar + symbol[i] + ", ";
                }
                grammar = grammar.left(grammar.size() - 2);
                grammar = grammar + "), (";
                for(int i = 0; i < al.length(); i++)
                {
                    grammar = grammar + al[i] + ", ";
                }
                grammar = grammar.left(grammar.size() - 2);
                grammar = grammar + "), P, S}";
                ui->textEdit->append(grammar);
                for(int i = 0; i < multiplicity * 2; i++)
                {
                    ui->textEdit->append(pl_rules[i]);
                }
            }
        }

        if(ui->radioButton->isChecked())
        {
            QString iss = ll_rules[0];
            iss.remove(0, 5);
            while(!iss.isEmpty())
            {
                if(iss.indexOf("|") >= 0)
                {
                    str = iss.left(iss.indexOf("|"));
                    iss.remove(0, iss.indexOf("|") + 1);
                }
                else
                {
                    str = iss.left(iss.length());
                    iss.remove(0, iss.length());
                }
                pre_chains.push_back(str);
                pair.first = str;
                pair.second = "0";
                full_chains.push_back(pair);
            }

            while(!pre_chains.empty())
            {
                int size = pre_chains.size();
                for(int i = 0; i < size; i++)
                {
                    int temp = 0;
                    if(pre_chains[0][0] == 'S')
                    {
                        temp = 0;
                    }
                    else
                    {
                        temp = pre_chains[0][0].unicode() - 64;
                    }
                    str1 = pre_chains[0];
                    str1.remove(0, 1);
                    if(str1.length() > end_range)
                    {
                        pre_chains.erase(pre_chains.begin());
                        continue;
                    }
                    else
                    {
                        QString iss = ll_rules[temp];
                        iss.remove(0, 5);
                        if(str1.length() < start_range)
                        {
                            while(!iss.isEmpty())
                            {
                                if(iss.indexOf("|") >= 0)
                                {
                                    str = iss.left(iss.indexOf("|"));
                                    iss.remove(0, iss.indexOf("|") + 1);
                                }
                                else
                                {
                                    str = iss.left(iss.length());
                                    iss.remove(0, iss.length());
                                }
                                if(str != QChar(0x3BB))
                                {
                                    str = str + str1;
                                    pair.first = str;
                                    pair.second = pre_chains[0];
                                    pre_chains.push_back(str);
                                    full_chains.push_back(pair);
                                }
                            }
                        }
                        else
                        {
                            while(!iss.isEmpty())
                            {
                                if(iss.indexOf("|") >= 0)
                                {
                                    str = iss.left(iss.indexOf("|"));
                                    iss.remove(0, iss.indexOf("|") + 1);
                                }
                                else
                                {
                                    str = iss.left(iss.length());
                                    iss.remove(0, iss.length());
                                }
                                if(str == QChar(0x3BB))
                                {
                                    if(chains.size() == 0)
                                    {
                                        chains.push_back(str1);
                                        pair.first = str1;
                                        pair.second = pre_chains[0];
                                        full_chains.push_back(pair);
                                        pre_chains.erase(pre_chains.begin());
                                        check = true;
                                    }
                                    for(int j = 0; j < chains.size(); j++)
                                    {
                                        if(chains[j] == str1)
                                        {
                                            break;
                                        }
                                        if(chains[j] != str1 && j == chains.size() - 1)
                                        {
                                            chains.push_back(str1);
                                            pair.first = str1;
                                            pair.second = pre_chains[0];
                                            full_chains.push_back(pair);
                                            pre_chains.erase(pre_chains.begin());
                                            check = true;
                                        }
                                    }
                                }
                                else
                                {
                                    str = str + str1;
                                    pair.first = str;
                                    pair.second = pre_chains[0];
                                    pre_chains.push_back(str);
                                    full_chains.push_back(pair);
                                }
                            }
                        }
                    }
                    if(!check)
                    {
                        pre_chains.erase(pre_chains.begin());
                    }
                    check = false;
                }
            }


            for(int i = full_chains.size() - 1; i >= 0; i--)
            {
                if(chains.contains(full_chains[i].first))
                {
                    index = chains.indexOf(full_chains[i].first);
                    parent = full_chains[i].second;
                    temp = i;
                    while(parent != "0")
                    {
                        chains[index] = parent + " -> " + chains[index];
                        for(int j = 0; j < i; j++)
                        {
                            if(full_chains[j].first == parent)
                            {
                                parent = full_chains[j].second;
                                j = i;
                            }
                        }
                    }
                }
            }
        }

        else
        {
            QString iss = pl_rules[0];
            iss.remove(0, 5);
            while(!iss.isEmpty())
            {
                if(iss.indexOf("|") >= 0)
                {
                    str = iss.left(iss.indexOf("|"));
                    iss.remove(0, iss.indexOf("|") + 1);
                }
                else
                {
                    str = iss.left(iss.length());
                    iss.remove(0, iss.length());
                }
                pre_chains.push_back(str);
                pair.first = str;
                pair.second = "0";
                full_chains.push_back(pair);
            }

            while(!pre_chains.empty())
            {
                int size = pre_chains.size();
                for(int i = 0; i < size; i++)
                {
                    int temp = 0;
                    if(pre_chains[0][pre_chains[0].length() - 1] == 'S')
                    {
                        temp = 0;
                    }
                    else
                    {
                        temp = pre_chains[0][pre_chains[0].length() - 1].unicode() - 64;
                    }
                    str1 = pre_chains[0];
                    str1.remove(str1.length() - 1, 1);
                    if(str1.length() > end_range)
                    {
                        pre_chains.erase(pre_chains.begin());
                        continue;
                    }
                    else
                    {
                        QString iss = pl_rules[temp];
                        iss.remove(0, 5);
                        if(str1.length() < start_range)
                        {
                            while(!iss.isEmpty())
                            {
                                if(iss.indexOf("|") >= 0)
                                {
                                    str = iss.left(iss.indexOf("|"));
                                    iss.remove(0, iss.indexOf("|") + 1);
                                }
                                else
                                {
                                    str = iss.left(iss.length());
                                    iss.remove(0, iss.length());
                                }
                                if(str != QChar(0x3BB))
                                {
                                    str = str1 + str;
                                    pair.first = str;
                                    pair.second = pre_chains[0];
                                    pre_chains.push_back(str);
                                    full_chains.push_back(pair);
                                }
                            }
                        }
                        else
                        {
                            while(!iss.isEmpty())
                            {
                                if(iss.indexOf("|") >= 0)
                                {
                                    str = iss.left(iss.indexOf("|"));
                                    iss.remove(0, iss.indexOf("|") + 1);
                                }
                                else
                                {
                                    str = iss.left(iss.length());
                                    iss.remove(0, iss.length());
                                }
                                if(str == QChar(0x3BB))
                                {
                                    if(chains.size() == 0)
                                    {
                                        chains.push_back(str1);
                                        pair.first = str1;
                                        pair.second = pre_chains[0];
                                        full_chains.push_back(pair);
                                        pre_chains.erase(pre_chains.begin());
                                        check = true;
                                    }
                                    for(int j = 0; j < chains.size(); j++)
                                    {
                                        if(chains[j] == str1)
                                        {
                                            break;
                                        }
                                        if(chains[j] != str1 && j == chains.size() - 1)
                                        {
                                            chains.push_back(str1);
                                            pair.first = str1;
                                            pair.second = pre_chains[0];
                                            full_chains.push_back(pair);
                                            pre_chains.erase(pre_chains.begin());
                                            check = true;
                                        }
                                    }
                                }
                                else
                                {
                                    str = str1 + str;
                                    pair.first = str;
                                    pair.second = pre_chains[0];
                                    pre_chains.push_back(str);
                                    full_chains.push_back(pair);
                                }
                            }
                        }
                    }
                    if(!check)
                    {
                        pre_chains.erase(pre_chains.begin());
                    }
                    check = false;
                }
            }


            for(int i = full_chains.size() - 1; i >= 0; i--)
            {
                if(chains.contains(full_chains[i].first))
                {
                    index = chains.indexOf(full_chains[i].first);
                    parent = full_chains[i].second;
                    temp = i;
                    while(parent != "0")
                    {
                        chains[index] = parent + " -> " + chains[index];
                        for(int j = 0; j < i; j++)
                        {
                            if(full_chains[j].first == parent)
                            {
                                parent = full_chains[j].second;
                                j = i;
                            }
                        }
                    }
                }
            }
        }

        ui->textEdit_2->setText("");
        for(int i = 0; i < chains.size(); i++)
        {
            int t = i + 1;
            chains[i] = QString::number(t) + ". " + chains[i];
            //str = full_chains[i].first + " - " + full_chains[i].second;
            ui->textEdit_2->append(chains[i]);
        }
        delete [] ll_rules;
        delete [] pl_rules;
    }
    full_chains.clear();
    chains.clear();
    pre_chains.clear();
}

void MainWindow::on_comboBox_2_currentIndexChanged(int index)
{
    if(index + 1 > ui->comboBox_3->currentIndex() + 1)
    {
        ui->comboBox_2->setCurrentIndex(ui->comboBox_3->currentIndex());
    }
}

void MainWindow::on_comboBox_3_currentIndexChanged(int index)
{
    if(index + 1 < ui->comboBox_2->currentIndex() + 1)
    {
        ui->comboBox_3->setCurrentIndex(ui->comboBox_2->currentIndex());
    }
}

void MainWindow::on_lineEdit_2_textChanged(const QString &arg1)
{
   if(!ui->lineEdit->text().contains(arg1.right(1)))
        ui->lineEdit_2->setText(arg1.left(arg1.size() - 1));
}

void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    if(arg1.size() > 0)
    {
        int temp = arg1.at(arg1.size() - 1).toLatin1();
        if(arg1.left(arg1.size() - 1).contains(arg1.right(1)))
            ui->lineEdit->setText(arg1.left(arg1.size() - 1));

        if(temp < 33 && temp != 8)
        {
            ui->lineEdit->setText(arg1.left(arg1.size() - 1));
        }
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this,
                                    QString::fromUtf8("Сохранить файл"),
                                    QDir::currentPath(),
                                    "Text document(*.txt *.docx *.doc);;All files (*.*)");
    QFile out(fileName);
    if( out.open( QIODevice::WriteOnly ) )
    {
        QTextStream stream(&out);
        stream << tr("Алфавит:\r\n");
        QString str = ui->lineEdit->text();
        stream << str << tr("\r\n");
        stream << tr("Подстрока:\r\n");
        str = ui->lineEdit_2->text();
        stream << str << tr("\r\n");
        stream << tr("Кратность:\r\n");
        int temp = ui->comboBox->currentIndex() + 1;
        stream << temp << tr("\r\n");
        stream << tr("Регулярная грамматика:\r\n");
        if(ui->radioButton->isChecked())
            stream << ui->radioButton->text() << tr("\r\n");
        else
            stream << ui->radioButton_2->text() << tr("\r\n");
        stream << tr("Минимальная длинна цепочки:\r\n");
        temp = ui->comboBox_2->currentIndex() + 1;
        stream << temp << tr("\r\n");
        stream << tr("Максимальная длинна цепочки:\r\n");
        temp = ui->comboBox_3->currentIndex() + 1;
        stream << temp << tr("\r\n");
        stream << tr("Правила:\r\n");
        str = ui->textEdit->toPlainText();
        QTextStream *qstream = new QTextStream(&str , QIODevice::ReadOnly);
        QVector<QString> lines;
        while(!qstream->atEnd())
        {
            lines << qstream->readLine();
        }
        for(int i = 0; i < lines.length(); i++)
        {
            stream << lines[i] << tr("\r\n");
        }
        stream << tr("Цепочки:\r\n");
        lines.clear();
        str = ui->textEdit_2->toPlainText();
        QTextStream *qstream2 = new QTextStream(&str , QIODevice::ReadOnly);
        while(!qstream2->atEnd())
        {
            lines << qstream2->readLine();
        }
        for(int i = 0; i < lines.length(); i++)
        {
            stream << lines[i] << tr("\r\n");
        }
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    QMessageBox::information(this, "Формат файла", "Файл должен иметь следующий вид:\n"
                             "1 строка: Алфавит. Пример: abcd\n"
                             "2 строка: Подцепочка. Если пустая - оставьте пустую строку. Пример: ad\n"
                             "3 строка: Кратность всех цепочек языка. Пример: 10\n"
                             "4 строка: Выбор, праволинейная или леволинейная грамматика: ПЛ и ЛЛ соответственно. Пример: ПЛ\n"
                             "5 строка: Минимальная длинна цепочек языка. Пример: 3\n"
                             "6 строка: Максимальная длинна цепочек языка. Пример: 6\n",  QMessageBox::Ok);

    QString fileName = QFileDialog::getOpenFileName(this,
                                    QString::fromUtf8("Открыть файл"),
                                    QDir::currentPath(),
                                    "Text document(*.txt *.docx *.doc);;All files (*.*)");
        QFile in(fileName);
        if(in.open( QIODevice::ReadOnly ) ) {
            QTextStream stream( &in );
            QString al, substr, multiplicity, regular, start_range, end_range;
            int temp;
            al = stream.readLine();
            ui->lineEdit->setText(al);
            substr = stream.readLine();
            ui->lineEdit_2->setText(substr);
            multiplicity = stream.readLine();
            temp = multiplicity.toInt();
            ui->comboBox->setCurrentIndex(temp);
            regular = stream.readLine();
            if(regular == "ПЛ" || regular == "Праволинейная")
                ui->radioButton_2->setChecked(true);
            else
                ui->radioButton->setChecked(true);
            start_range = stream.readLine();
            temp = start_range.toInt() - 1;
            ui->comboBox_2->setCurrentIndex(temp);
            end_range = stream.readLine();
            temp = end_range.toInt() - 1;
            ui->comboBox_3->setCurrentIndex(temp);
            in.close();
        }
}

void MainWindow::on_action_triggered()
{
    QMessageBox::information(this, "Автор", "Гайкин Никита Сергеевич");
}

void MainWindow::on_action_2_triggered()
{
    QMessageBox::information(this, "Автор", "Разработать программу, которая по введённым алфавиту, подцепочке и кратности выходных цепочек построит ЛЛ или ПЛ регулярную грамматику и выведет все цепочки");
}
