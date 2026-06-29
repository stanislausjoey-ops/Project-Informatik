QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    abstractmap.cpp \
    addcitydialog.cpp \
    city.cpp \
    createstreetdialog.cpp \
    dijkstra.cpp \
    main.cpp \
    mainwindow.cpp \
    map.cpp \
    mapio.cpp \
    mapionrw.cpp \
    street.cpp

HEADERS += \
    abstractmap.h \
    addcitydialog.h \
    city.h \
    createstreetdialog.h \
    dijkstra.h \
    mainwindow.h \
    map.h \
    mapio.h \
    mapionrw.h \
    street.h

FORMS += \
    addcitydialog.ui \
    createstreetdialog.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Doxyfile \
    html/abstractmap_8h_source.html \
    html/addcitydialog_8h_source.html \
    html/annotated.html \
    html/annotated_dup.js \
    html/bc_s.png \
    html/bc_sd.png \
    html/city_8h_source.html \
    html/class_abstract_map-members.html \
    html/class_abstract_map.html \
    html/class_abstract_map.js \
    html/class_abstract_map.png \
    html/class_city-members.html \
    html/class_city.html \
    html/class_city.js \
    html/class_dijkstra-members.html \
    html/class_dijkstra.html \
    html/class_main_window-members.html \
    html/class_main_window.html \
    html/class_main_window.png \
    html/class_map-members.html \
    html/class_map.html \
    html/class_map.js \
    html/class_map.png \
    html/class_map_io-members.html \
    html/class_map_io.html \
    html/class_map_io.js \
    html/class_map_io.png \
    html/class_map_io_nrw-members.html \
    html/class_map_io_nrw.html \
    html/class_map_io_nrw.js \
    html/class_map_io_nrw.png \
    html/class_street-members.html \
    html/class_street.html \
    html/class_street.js \
    html/class_tuppel-members.html \
    html/class_tuppel.html \
    html/classadd_city_dialog-members.html \
    html/classadd_city_dialog.html \
    html/classadd_city_dialog.js \
    html/classadd_city_dialog.png \
    html/classcreate_street-members.html \
    html/classcreate_street.html \
    html/classcreate_street.js \
    html/classcreate_street.png \
    html/classes.html \
    html/clipboard.js \
    html/closed.png \
    html/cookie.js \
    html/createstreetdialog_8h_source.html \
    html/dijkstra_8h_source.html \
    html/doc.svg \
    html/docd.svg \
    html/doxygen.css \
    html/doxygen.svg \
    html/doxygen_crawl.html \
    html/dynsections.js \
    html/files.html \
    html/files_dup.js \
    html/folderclosed.svg \
    html/folderclosedd.svg \
    html/folderopen.svg \
    html/folderopend.svg \
    html/functions.html \
    html/functions_func.html \
    html/hierarchy.html \
    html/hierarchy.js \
    html/index.html \
    html/jquery.js \
    html/mainwindow_8h_source.html \
    html/map_8h_source.html \
    html/mapio_8h_source.html \
    html/mapionrw_8h_source.html \
    html/minus.svg \
    html/minusd.svg \
    html/nav_f.png \
    html/nav_fd.png \
    html/nav_g.png \
    html/nav_h.png \
    html/nav_hd.png \
    html/navtree.css \
    html/navtree.js \
    html/navtreedata.js \
    html/navtreeindex0.js \
    html/open.png \
    html/plus.svg \
    html/plusd.svg \
    html/resize.js \
    html/search/all_0.js \
    html/search/all_1.js \
    html/search/all_2.js \
    html/search/all_3.js \
    html/search/all_4.js \
    html/search/all_5.js \
    html/search/all_6.js \
    html/search/all_7.js \
    html/search/all_8.js \
    html/search/all_9.js \
    html/search/all_a.js \
    html/search/classes_0.js \
    html/search/classes_1.js \
    html/search/classes_2.js \
    html/search/classes_3.js \
    html/search/classes_4.js \
    html/search/classes_5.js \
    html/search/close.svg \
    html/search/functions_0.js \
    html/search/functions_1.js \
    html/search/functions_2.js \
    html/search/functions_3.js \
    html/search/functions_4.js \
    html/search/functions_5.js \
    html/search/functions_6.js \
    html/search/functions_7.js \
    html/search/functions_8.js \
    html/search/functions_9.js \
    html/search/mag.svg \
    html/search/mag_d.svg \
    html/search/mag_sel.svg \
    html/search/mag_seld.svg \
    html/search/search.css \
    html/search/search.js \
    html/search/searchdata.js \
    html/splitbar.png \
    html/splitbard.png \
    html/street_8h_source.html \
    html/sync_off.png \
    html/sync_on.png \
    html/tab_a.png \
    html/tab_ad.png \
    html/tab_b.png \
    html/tab_bd.png \
    html/tab_h.png \
    html/tab_hd.png \
    html/tab_s.png \
    html/tab_sd.png \
    html/tabs.css \
    latex/abstractmap_8h_source.tex \
    latex/addcitydialog_8h_source.tex \
    latex/annotated.tex \
    latex/city_8h_source.tex \
    latex/class_abstract_map.eps \
    latex/class_abstract_map.tex \
    latex/class_city.tex \
    latex/class_dijkstra.tex \
    latex/class_main_window.eps \
    latex/class_main_window.tex \
    latex/class_map.eps \
    latex/class_map.tex \
    latex/class_map_io.eps \
    latex/class_map_io.tex \
    latex/class_map_io_nrw.eps \
    latex/class_map_io_nrw.tex \
    latex/class_street.tex \
    latex/class_tuppel.tex \
    latex/classadd_city_dialog.eps \
    latex/classadd_city_dialog.tex \
    latex/classcreate_street.eps \
    latex/classcreate_street.tex \
    latex/createstreetdialog_8h_source.tex \
    latex/dijkstra_8h_source.tex \
    latex/doxygen.sty \
    latex/etoc_doxygen.sty \
    latex/files.tex \
    latex/hierarchy.tex \
    latex/longtable_doxygen.sty \
    latex/mainwindow_8h_source.tex \
    latex/make.bat \
    latex/map_8h_source.tex \
    latex/mapio_8h_source.tex \
    latex/mapionrw_8h_source.tex \
    latex/refman.tex \
    latex/street_8h_source.tex \
    latex/tabu_doxygen.sty
