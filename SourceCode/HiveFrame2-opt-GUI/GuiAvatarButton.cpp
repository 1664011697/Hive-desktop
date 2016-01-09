#include "GuiAvatarButton.h"
#include <QDebug>
GuiAvatarButton::GuiAvatarButton(QString pa7th, const int Diameter, int borderWidth, QWidget *parent)
{
  qDebug()<<"final ava"<<pa7th;

  diameter = Diameter;
  border_width = borderWidth;

  QBitmap mask(QSize(Diameter,Diameter));
  QPainter painter(&mask);
  painter.setRenderHint(QPainter::Antialiasing);
  painter.setRenderHint(QPainter::SmoothPixmapTransform);
  painter.fillRect(0, 0, Diameter, Diameter, Qt::white);
  painter.setBrush(QColor(0, 0, 0));
  painter.drawRoundedRect(0, 0, Diameter, Diameter, 99, 99);

  QPixmap avatar_pixmap(pa7th);
  avatar_pixmap = avatar_pixmap.scaled(Diameter,Diameter,Qt::IgnoreAspectRatio,Qt::SmoothTransformation);

  avatar_pixmap.setDevicePixelRatio(2.0);
  avatar_pixmap.setMask(mask);

  this->setPixmap(avatar_pixmap);
  this->setParent(parent);
}


////////////events

void GuiAvatarButton::mouseReleaseEvent(QMouseEvent *ev)
{
  if (ev->button() == Qt::LeftButton);
  emit clicked();
}

void GuiAvatarButton::enterEvent(QEvent * )
{
  //setState1();
  //emit entered();
}

void GuiAvatarButton::leaveEvent(QEvent *)
{
  //setState0();
  //emit left();
}


/*
void getRoundPixmap(QPixmap& src,QSize size)

{

  QImage resultImage(size,QImage::Format_ARGB32_Premultiplied);

  QPixmap head_mask("mask.png");

  QPainter painter(&resultImage);

  painter.setCompositionMode(QPainter::CompositionMode_Source);

  painter.fillRect(resultImage.rect(), Qt::transparent);

  painter.setCompositionMode(QPainter::CompositionMode_SourceOver);

  painter.drawPixmap(0, 0, head_mask);

  painter.setCompositionMode(QPainter::CompositionMode_SourceOut);

  painter.drawPixmap(0, 0, src.scaled(size));

  painter.setCompositionMode(QPainter::CompositionMode_DestinationOver);

  painter.end();



  src = QPixmap::fromImage(resultImage);

}
*/