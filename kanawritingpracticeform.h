/*
** Copyright 2007-2013, 2017 Sólyom Zoltán
** This file is part of zkanji, a free software released under the terms of the
** GNU General Public License version 3. See the file LICENSE for details.
**/

#ifndef KANAWRITINGPRACTICEFORM_H
#define KANAWRITINGPRACTICEFORM_H

#include "dialogwindow.h"
#include "zitemscroller.h"

namespace Ui {
    class KanaWritingPracticeForm;
}

class QLabel;
class KanaWritingPracticeForm : public DialogWindow
{
    Q_OBJECT
public:
    KanaWritingPracticeForm(QWidget *parent = nullptr);
    ~KanaWritingPracticeForm();

    void exec();

public slots:
    void on_restartButton_clicked();

    void candidatesChanged(const std::vector<int> &l);
    void candidateClicked(int index);

    void on_gridButton_toggled(bool checked);
    void on_clearButton_clicked();
    void on_prevButton_clicked();
    void on_nextButton_clicked();
    void on_revealButton_clicked();
protected:
    virtual bool event(QEvent *e) override;
private:
    // Generates a list of syllables to be shown and restarts the test.
    void reset();
    // Updates the form to show the next syllable.
    void next();

    void answered(bool correct);

    // Stops the test timer and if hide is true, hides the labels showing the passed time.
    void stopTimer(bool hide);
    // Resets the timer and shows the labels showing the passed time.
    void startTimer();

    // Start to show the next character while animating the current syllable.
    void animateNext(int index = -1, bool ended = true);

    void hideLabelAnimation();

    Ui::KanaWritingPracticeForm *ui;

    // Time the test started.
    QDateTime starttime;

    // Indexes of syllables in kanaStrings[]  (from kanapracticesettingsform.h) to be shown to
    // the student.
    std::vector<int> list;

    CandidateKanjiScrollerModel *candidates;

    // Current syllable position in list.
    int pos;
    // Number of times the current syllable has been retried. After 2 the syllable is marked
    // as a mistake.
    int retries;
    // Number of mistakes made in the whole test. Not counted below 2 retries.
    int mistakes;

    // Current character position of the drawn syllable in the current answer. Used when
    // displaying the character drawing animation on request.
    int animatepos;

    QString entered;

    // Label showing number of items due to be tested.
    QLabel *dueLabel;

    // Label showing number of items that were retried twice and failed.
    QLabel *wrongLabel;

    // Label showing passed time.
    QLabel *timeLabel;

    // Timer used to show passed time.
    QBasicTimer timer;
    // Timer used in stroke animation to delay next kana.
    QTimer *t;

    typedef DialogWindow    base;
};

#endif // KANAWRITINGPRACTICEFORM_H