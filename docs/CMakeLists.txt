include (UseLATEX)

add_latex_document (RootTuple-doc.tex 
    CONFIGURE RootTuple-doc.tex
    DEFAULT_PDF)

install (FILES ${CMAKE_BINARY_DIR}/docs/RootTuple-doc.tex 
    RENAME RootTuple-doc-${CPACK_PACKAGE_VERSION}.tex 
    DESTINATION docs)

install (FILES ${CMAKE_BINARY_DIR}/docs/RootTuple-doc.pdf
    RENAME RootTuple-doc-${CPACK_PACKAGE_VERSION}.pdf
    OPTIONAL
    DESTINATION docs)
