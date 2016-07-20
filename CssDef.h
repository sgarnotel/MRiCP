#ifndef CSSDEF_H
#define CSSDEF_H


#include "ImgDef.h"


#define CSS_GRAPH_BRUSH_B   IMG_BLUE
#define CSS_GRAPH_BRUSH_R   IMG_RED
#define CSS_GRAPH_BRUSH_G   IMG_GREEN
#define CSS_GRAPH_BRUSH_M   IMG_MAGENTA

#ifdef NO_CSS

#define CSS_MAINWINDOW      ""
#define CSS_MENUBAR         ""
#define CSS_MENU            ""
#define CSS_STATUSBAR       ""
#define CSS_TOOLBAR         ""
#define CSS_TAB             ""
#define CSS_TABBAR          ""
#define CSS_WIDGET          ""
#define CSS_LABEL_TITLE     "QLabel {color:gray; font-size:20px; padding:0px 0px 0px 10px; margin: 0px;}"
#define CSS_LABEL_SPACE     ""
#define CSS_LABEL_GLOBAL    "QLabel {color:gray; border:none;}"
#define CSS_LABEL_BIG       "QLabel {color:gray; font-size:16px;}"
#define CSS_LABEL_WARNING   "QLabel {color:red;}"
#define CSS_LABEL_RED       "QLabel {color:red;}"
#define CSS_SLIDER          ""
#define CSS_RADIO           ""
#define CSS_BUTTON          ""
#define CSS_COMBOBOX        ""
#define CSS_CHECKBOX        ""
#define CSS_DSPINBOX        ""
#define CSS_SPINBOX         ""
#define CSS_DIALOG          ""
#define CSS_SCROLL_AREA     ""

#else
#ifdef NORMAL_CSS

#define CSS_MAINWINDOW      "QMainWindow {background-color:white;}"
#define CSS_MENUBAR         "QMenuBar {background-color:white;} QMenuBar::item {background-color:white; color:gray;}"
#define CSS_MENU            "QMenu::item:selected {background-color:gray;}"
#define CSS_STATUSBAR       "QStatusBar {background-color:white; border:1px solid gray;} QStatusBar::item {border:none;}"
#define CSS_TOOLBAR         "QToolBar {background-color:white;}"
#define CSS_TAB             "QTabWidget::pane {background-color:white;}"
#define CSS_TABBAR          "QTabBar::tab {background-color:white; border:1px solid black; margin:5px; padding:5px; border-radius:5px;}"
#define CSS_WIDGET          "QWidget {background-color:white;}"
#define CSS_LABEL_TITLE     "QLabel {color:gray; font-size:20px; padding:0px 0px 0px 10px; margin: 0px;}"
#define CSS_LABEL_SPACE     "QLabel {background-color:LightGray; max-width:2px;}"
#define CSS_LABEL_GLOBAL    "QLabel {color:gray; border:none;}"
#define CSS_LABEL_BIG       "QLabel {color:gray; font-size:16px;}"
#define CSS_LABEL_WARNING   "QLabel {color:red;}"
#define CSS_SLIDER          "QSlider::groove:horizontal{border: 1px solid gray; height: 4px; background:#EEEEFF; margin: 2px 0;} QSlider::handle:horizontal {background:gray; border: 1px solid gray; width: 18px; margin: -2px 0; border-radius: 3px;}"
#define CSS_RADIO           "QRadioButton {color:gray; padding:2px;}"
#define CSS_BUTTON          "QPushButton {background:#EEEEFF; padding:1px; border:1px solid gray; border-radius:5px;}"
#define CSS_COMBOBOX        "QComboBox {background-color:#EEEEFF; color:gray; border:1px solid gray; border-radius:3px; padding:1px 18px 1px 3px;} QComboBox::down-arrow{image:url(./img/ldarrow_small.png);} QComboBox::drop-down{border:none;}  QComboBox QAbstractItemView {background-color:#EEEEFF;}"
#define CSS_CHECKBOX        "QCheckBox {background-color:white;} QCheckBox::indicator:unchecked{image:url(./img/unchecked.png); width:16px;} QCheckBox::indicator:checked{image:url(./img/checked.png); width:16px;}"
#define CSS_DSPINBOX        "QDoubleSpinBox {background-color:#EEEEFF;}"
#define CSS_SPINBOX         "QSpinBox {background-color:#EEEEFF;}"
#define CSS_DIALOG          "QDialog {background-color:white;}"
#define CSS_SCROLL_AREA     "QScrollArea {background-color:white; border-radius:5px;}"

#endif
#endif


#endif // CSSDEF_H
