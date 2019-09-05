
import string
import sys
import re
from xml.dom.minidom import Document

keyword=['auto','break','case','char','const','continue','default',\
    'do','double','else','enum','extern','float','for','goto','if',\
    'inline','int','long','register','restrict','return','short',\
    'signed','sizeof','static','struct','switch','typedef',\
    'union','unsigned','void','volatile','while']
separator=['[',']','(',')','{','}','.','/',':',';','...',',','#',\
            '##','<:',':>','<%','%>','%:','%:%:']
operator=['->','++','--','&','*','+','-','~','!','%','<<','>>','<',\
        '>','<=','>=','==','!=','^','|','&&''||','?','=','*=','/=','%=',\
        '+=','-=','<<=','>>=','&=','^=','|=','']
identifier=re.compile(r'^[a-zA-Z\_][a-zA-Z0-9\_]*$')
integer_constant=re.compile(r'[+-]?[1-9][0-9]+|[+-]?0[0-7]+|[+-]?0[xX][0-9a-fA-F]+')
floating_constant_D=re.compile(r'[-+]?([0-9]+(\.[0-9]+)?|\.[0-9]+)([eE][-+]?[0-9]+)?')
floating_constant_H=re.compile\
    (r'[-+]?0[xX]([0-9a-fA-F]+(\.[0-9a-fA-F]+)?|\.[0-9a-fA-F]+)([pP][-+]?[0-9a-fA-F]+)?')
character_constant=re.compile(r'^\'[^\'\\]\'&')
string_literal=re.compile(r'^\"[^\'\\]+\"&')


def writeXml(number,value,typeOut,line,valid):
    number=str(number)
    line=str(line)
    #print(number+' '+value+' '+typeOut+' '+line+' '+valid)
    token=doc.createElement('token')
    numberI=doc.createElement('number')
    num=doc.createTextNode(number)
    numberI.appendChild(num)
    token.appendChild(numberI)

    valueI=doc.createElement('value')
    val=doc.createTextNode(value)
    valueI.appendChild(val)
    token.appendChild(valueI)

    typeI=doc.createElement('type')
    typ=doc.createTextNode(typeOut)
    typeI.appendChild(typ)
    token.appendChild(typeI)

    lineI=doc.createElement('line')
    lin=doc.createTextNode(line)
    lineI.appendChild(lin)
    token.appendChild(lineI)

    validI=doc.createElement('valid')
    vali=doc.createTextNode(valid)
    validI.appendChild(vali)
    token.appendChild(validI)

    tokens.appendChild(token)
def scanner(sourceFilePath,targetFilePath):    
    sou=open(sourceFilePath)
    lines=sou.readlines()
    num=0
    lineNum=0
    #for lines in sourcefile:
    for line in lines:
        lineNum+=1
        for token in line.split():
            num+=1
            #print("words:"+token)
            #匹配关键字
            if(token in keyword):
                #print("keyword")
                writeXml(num,token,'keyword',lineNum,'true')
            #匹配分隔符
            elif(token in separator):
                #print("separator")
                writeXml(num,token,'separator',lineNum,'true')
            #匹配运算符
            elif (token in operator):
                #print("operator")
                writeXml(num,token,'operator',lineNum,'true')
            #匹配标识符
            elif (re.fullmatch(identifier,token)):
                #print('identifier')
                writeXml(num,token,'identifier',lineNum,'true')
            #匹配整形常量
            elif (re.fullmatch(integer_constant,token)):
                #print("integer_constant")
                writeXml(num,token,'integer_constant',lineNum,'true')
            #匹配浮点型常量
            elif (re.fullmatch(floating_constant_D,token) or re.fullmatch(floating_constant_H,token)):
                #print("floating_constant")
                writeXml(num,token,'floating_constant',lineNum,'true')
            #匹配字符串常量
            elif (re.fullmatch(string_literal,token)):
                #print("string_literal")
                writeXml(num,token,'string_literal',lineNum,'true')
            #匹配字符常量
            elif (re.fullmatch(character_constant,token)):
                #print("character_constant")
                writeXml(num,token,'character_constant',lineNum,'true')
            else:
                writeXml(num,token,'unknow',lineNum,'false')
    fp=open(targetFilePath,'w')
    doc.writexml(fp,indent='\t',newl='\n',addindent='\t',encoding='utf-8')
    fp.close()           
if __name__ == "__main__":
    #sourceFile='test.c'
    #targetFile='testResult.xml'
    sourceFile=sys.argv[1]
    targetFile=sys.argv[2]
    doc=Document()
    DOCUMENT=doc.createElement('project')
    DOCUMENT.setAttribute('name',sourceFile)
    doc.appendChild(DOCUMENT)
    tokens=doc.createElement('tokens')
    DOCUMENT.appendChild(tokens)
    scanner(sourceFile,targetFile)
    print("2.myScanner finished!")
    

