﻿#ifndef QCEFVIEWTEST_H
#define QCEFVIEWTEST_H

#include <QtWidgets/QMainWindow>

#include "CefViewWidget.h"
#include "ui_MainWindow.h"

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  MainWindow(QWidget* parent = 0);
  ~MainWindow();

protected slots:
  void onBtnChangeColorClicked();

  void onDraggableRegionChanged(const QRegion& draggableRegion, const QRegion& nonDraggableRegion);

  void onInvokeMethod(int browserId, int frameId, const QString& method, const QVariantList& arguments);

  void onQCefQueryRequest(const QCefQuery& query);

  void onQCefUrlRequest(const QString& url);

private:
#if QT_VERSION >= QT_VERSION_CHECK(6, 0, 0)
  virtual bool nativeEvent(const QByteArray& eventType, void* message, qintptr* result);
#else
  virtual bool nativeEvent(const QByteArray& eventType, void* message, long* result);
#endif

private:
  Ui::MainWindow ui;

  CefViewWidget* cefViewWidget;
  QRegion draggableRegion_;
  QRegion nonDraggableRegion_;
};

#endif // QCEFVIEWTEST_H