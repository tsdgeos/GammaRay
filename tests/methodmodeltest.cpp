/*
  methodmodeltest.cpp

  This file is part of GammaRay, the Qt application inspection and
  manipulation tool.

  Copyright (C) 2016 Klarälvdalens Datakonsult AB, a KDAB Group company, info@kdab.com
  Author: Volker Krause <volker.krause@kdab.com>

  Licensees holding valid commercial KDAB GammaRay licenses may use this file in
  accordance with GammaRay Commercial License Agreement provided with the Software.

  Contact info@kdab.com if any conditions of this licensing are not clear to you.

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <core/objectmethodmodel.h>

#include <3rdparty/qt/modeltest.h>

#include <QDebug>
#include <QtTest/qtest.h>
#include <QObject>

#ifndef Q_MOC_RUN
#define MY_TAG
#endif

#if QT_VERSION < QT_VERSION_CHECK(5, 1, 0)
#define Q_REVISION(v)
#endif

using namespace GammaRay;

class MethodModelTest : public QObject
{
    Q_OBJECT
public slots:
    MY_TAG void taggedSlot() {}
    Q_REVISION(1407) void revisionedSlot() {}

private:
    QModelIndex indexForSignature(const QString &signature, QAbstractItemModel *model)
    {
        for (int i = 0; i < model->rowCount(); ++i) {
            const auto idx = model->index(i, 0);
            if (idx.data().toString().contains(signature))
                return idx;
        }
        return QModelIndex();
    }

private slots:
    void modelTest()
    {
        ObjectMethodModel model;
        ModelTest modelTest(&model);

        model.setMetaObject(&QObject::staticMetaObject);
        model.setMetaObject(&staticMetaObject);
        model.setMetaObject(Q_NULLPTR);
    }

    void testModel()
    {
        ObjectMethodModel model;
        model.setMetaObject(&staticMetaObject);

        QVERIFY(model.rowCount() > 0);

        auto idx = indexForSignature("deleteLater()", &model);
        QVERIFY(idx.isValid());
        QCOMPARE(idx.sibling(idx.row(), 1).data().toString(), QLatin1String("Slot"));
        QCOMPARE(idx.sibling(idx.row(), 2).data().toString(), QLatin1String("Public"));
        QCOMPARE(idx.sibling(idx.row(), 3).data().toString(), QLatin1String("QObject"));

        model.setMetaObject(Q_NULLPTR);
        QCOMPARE(model.rowCount(), 0);
    }

    void testToolTip_data()
    {
        QTest::addColumn<QString>("name");
        QTest::addColumn<QString>("toolTip");

        QTest::newRow("tagged") << "taggedSlot" << "MY_TAG";
#if QT_VERSION >= QT_VERSION_CHECK(5, 1, 0)
        QTest::newRow("revision") << "revisionedSlot" << "1407";
#endif
    }

    void testToolTip()
    {
        QFETCH(QString, name);
        QFETCH(QString, toolTip);

        ObjectMethodModel model;
        model.setMetaObject(&staticMetaObject);

        auto idx = indexForSignature(name, &model);
        QVERIFY(idx.isValid());
        QCOMPARE(model.columnCount(), 4);
        for (int i = 0; i < model.columnCount(); ++i) {
            QVERIFY(idx.sibling(idx.row(), i).data(Qt::ToolTipRole).toString().contains(toolTip));
        }
    }
};

QTEST_MAIN(MethodModelTest)

#include "methodmodeltest.moc"
