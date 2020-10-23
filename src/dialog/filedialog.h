#ifndef FILEDIALOG_H
#define FILEDIALOG_H

#include "dialog/dialog.h"

#include <QListWidget>
#include <QTimer>

#include <memory>

class Application;
namespace Ui
{
  class FileDialog;
}

class FileDialog
    : public Dialog
{
  Q_OBJECT

public:
  enum Type
  {
    LoadGame = 0,
    LoadMap = 1,
    SaveGame = 2,
    SaveMap = 3,
    DeleteGame = 4,
    DeleteMap = 5
  };

public:
  TIBERIUS_LIB_DECL explicit FileDialog(QWidget * parentWidget = nullptr);
  TIBERIUS_LIB_DECL ~FileDialog();

public:
  TIBERIUS_LIB_DECL QString fileName() const;
  TIBERIUS_LIB_DECL Type type() const;
  TIBERIUS_LIB_DECL void setFileName(const QString & fileName);
  TIBERIUS_LIB_DECL void setType(Type type);

protected:
  void showEvent(QShowEvent * event) override;

private:
  void init();
  void loadFiles();
  void warnFileExistence();
  QString getTitleString();

private slots:
  void handleCancel();
  void handleItemChanged(QListWidgetItem * currentItem, QListWidgetItem * prevItem);
  void handleOk();
  void handleScroll(int value);
  void resetFileWarning();
  void updateData();

private:
  void updateScrollBar();

private:
  std::unique_ptr<Ui::FileDialog> mUi;
  Type mType;
  QString mExtension;
  QString mFileName;
  QTimer mFileWarnTimer;
};

inline FileDialog::Type FileDialog::type() const
{
  return mType;
}

#endif // FILEDIALOG_H
