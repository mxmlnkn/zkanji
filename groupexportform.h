#ifndef GROUPEXPORTFORM_H
#define GROUPEXPORTFORM_H

#include <QPushButton>
#include "dialogwindow.h"

namespace Ui {
    class GroupExportForm;
};

class Dictionary;
class CheckedGroupTreeModel;
class GroupExportForm : public DialogWindow
{
    Q_OBJECT
public:
    GroupExportForm(QWidget *parent = nullptr);
    ~GroupExportForm();

    bool exec(Dictionary *dict);
public slots:
    void exportClicked();
    void modelDataChanged();
    void on_dictCBox_currentIndexChanged(int ix);
private:
    Ui::GroupExportForm *ui;

    QPushButton *exportbutton;
    CheckedGroupTreeModel *kanjimodel;
    CheckedGroupTreeModel *wordsmodel;

    typedef DialogWindow base;
};


#endif // GROUPEXPORTFORM_H
