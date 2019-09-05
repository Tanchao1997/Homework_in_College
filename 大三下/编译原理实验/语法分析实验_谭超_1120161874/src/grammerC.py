import xml.etree.ElementTree as ET
from xml.dom import minidom
import sys

dom=minidom.Document()
parserTree=dom.createElement("parserTree")
dom.appendChild(parserTree)

class Global:
    def __init__(self):
        self.currentLocation=0
        self.value=[]
        self.type=[]
        self.length=0
        self.datatype={'int','float','void','char','double','long','short'}
        self.operator={'&','*','+','-','%','<<','>>','<',\
        '>','<=','>=','==','!=','^','|','&&''||','*=','/=','%=',\
        '+=','-=','<<=','>>=','&=','^=','|=','='}
        self.constant={'integer_constant','floating_constant','string_literal','character_constant'}
        self.tokenStack=[]
        self.tokenStackLength=0

gl=Global()
gl.tokenStack.append(parserTree)
gl.tokenStackLength+=1

def pushXML(name, token=' '):
    tem=dom.createElement(name)
    gl.tokenStack[gl.tokenStackLength-1].appendChild(tem)
    gl.tokenStack.append(tem)
    gl.tokenStackLength+=1
    if(token!=' '):
        temText=dom.createTextNode(token)
        tem.appendChild(temText)

def popXML():
    gl.tokenStack.pop()
    gl.tokenStackLength-=1



def readXML(sourceFile):
    tree=ET.parse(sourceFile)
    root=tree.getroot()
    for vv in root.iter('value'):
        gl.value.append(vv.text)
        gl.length+=1
    for tt in root.iter('type'):
        gl.type.append(tt.text)

def program():
    print("program") 
    pushXML('program')
    funclist()
    popXML()
    return 0

def funclist():
    print("funclist")
    if(gl.currentLocation>=gl.length):
        return 0
    pushXML('funclist')
    if(gl.value[gl.currentLocation] in gl.datatype):
        pushXML('datatype',gl.value[gl.currentLocation])
        popXML()
        gl.currentLocation+=1
        if(gl.type[gl.currentLocation]=='identifier'):
            pushXML('identifier',gl.value[gl.currentLocation])
            popXML()
            gl.currentLocation+=1
            if(gl.value[gl.currentLocation]=='('):
                function()
                funclist()
            elif(gl.value[gl.currentLocation] in {'=',';'}):
                global_variable()
                funclist()
            else:
                print("func_list: function|global_variable Error")
                exit(1)
        else:
            print("func_list: ID Error")
            exit(1)
    popXML()
def function():
    print("function")
    pushXML('function')
    if(gl.value[gl.currentLocation]=='('):
        pushXML('seperator','(')
        popXML()
        gl.currentLocation+=1
        arg_list()
        if(gl.value[gl.currentLocation]==')'):
            pushXML('seperator',')')
            popXML()
            gl.currentLocation+=1
            code_blocks()
        else:
            print("function: ')' ERROR")
            exit(1)
    else:
        print("function:'(' ERROR")
        exit(1)
    popXML()
def global_variable():
    print("global_variable")
    pushXML('global_variable')
    if(gl.value[gl.currentLocation]==';'):
        pushXML('separator',';')
        popXML()
        gl.currentLocation+=1
    elif(gl.value[gl.currentLocation]=='='):
        pushXML('operator','=')
        popXML()
        gl.currentLocation+=1
        assignment_expression()
    else:
        print("global_veriable: ERROR")
    popXML()

def arg_list():
    print("arg_list")
    pushXML('arg_list')
    if(gl.value[gl.currentLocation] in gl.datatype):
        argument()
        if(gl.value[gl.currentLocation]==','):
            pushXML('separator',',')
            popXML()
            gl.currentLocation+=1
            arg_list()
    popXML()

def argument():
    print("argument")
    pushXML('argument')
    if(gl.value[gl.currentLocation] in gl.datatype):
        pushXML('datatype',gl.value[gl.currentLocation])
        popXML()
        gl.currentLocation+=1
        if(gl.type[gl.currentLocation]=='identifier'):
            pushXML('identifier',gl.value[gl.currentLocation])
            popXML()
            gl.currentLocation+=1
        else:
            print("argument: ID ERROR")
            exit(1)
    else:
        print("argument: TYPE ERROR")
    popXML()

def code_blocks():
    print("code_blocks")
    pushXML('code_blocks')
    if(gl.value[gl.currentLocation]=='{'):
        pushXML('separator','{')
        popXML()
        gl.currentLocation+=1
        statement_list()
        if(gl.value[gl.currentLocation]=='}'):
            pushXML('separator','}')
            popXML()
            gl.currentLocation+=1
        else:
            print("code_blocks: '}' ERROR")
            exit(1)
    else:
        print("code_blocks: '{' ERROR")
    popXML()

def statement_list():
    print("statement_list")
    pushXML('statement_list')
    if(gl.value[gl.currentLocation] in gl.datatype):
        declare_expression()
        if(gl.value[gl.currentLocation]==';'):
            pushXML('separator',';')
            popXML()
            gl.currentLocation+=1
            statement_list()
        else:
            print("statement_list: declare_expression ; ERROR")
            exit(1)
    elif(gl.type[gl.currentLocation]=='identifier' or gl.value[gl.currentLocation] in gl.constant):
        assignment_expression()
        if(gl.value[gl.currentLocation]==';'):
            pushXML('separator',';')
            popXML()
            gl.currentLocation+=1
            statement_list()
        else:
            print("statement_list: assignment ; ERROR")
    elif(gl.value[gl.currentLocation]=='while'):
        while_expression()
        statement_list()
    elif(gl.value[gl.currentLocation]=='for'):
        for_expression()
        statement_list()
    elif(gl.value[gl.currentLocation]=='if'):
        if_expression()
        statement_list()
    elif(gl.value[gl.currentLocation]=='return'):
        return_expression()
        if(gl.value[gl.currentLocation]==';'):
            gl.currentLocation+=1
        else:
            print("statement_list: return ; ERROR")
    popXML()

def declare_expression():
    print("declare_expression")
    pushXML('declare_expression')
    if(gl.value[gl.currentLocation] in gl.datatype):
        pushXML('datatype',gl.value[gl.currentLocation])
        popXML()
        gl.currentLocation+=1
        if(gl.type[gl.currentLocation]=='identifier'):
            pushXML('identifier',gl.value[gl.currentLocation])
            popXML()
            gl.currentLocation+=1
            if(gl.value[gl.currentLocation]=='='):
                pushXML('operator','=')
                popXML()
                gl.currentLocation+=1
                assignment_expression()
        else:
            print("declare_expression: ID ERROR")
    else:
        print("declare_expression: TYPE ERROR")
    popXML()
def assignment_expression():
    print("assignment_expression")
    pushXML('assignment_expression')
    if(gl.type[gl.currentLocation]=='identifier'):
        pushXML('identifier',gl.value[gl.currentLocation])
        popXML()
        gl.currentLocation+=1
        if(gl.value[gl.currentLocation] in gl.operator):
            pushXML('operator',gl.value[gl.currentLocation])
            popXML()
            gl.currentLocation+=1
            assignment_expression()
    elif(gl.type[gl.currentLocation] in gl.constant):
        pushXML('constant',gl.value[gl.currentLocation])
        popXML()
        gl.currentLocation+=1
        if(gl.value[gl.currentLocation] in gl.operator):
            pushXML('operator',gl.value[gl.currentLocation])
            popXML()
            gl.currentLocation+=1
            assignment_expression()
    else:
        print("assignmet_expression: ERROR")
    popXML()

def while_expression():
    print("while_expression")
    pushXML('while_expression')
    if(gl.value[gl.currentLocation]=='while'):
        pushXML('loop','while')
        popXML()
        gl.currentLocation+=1
        if(gl.value[gl.currentLocation]=='('):
            pushXML('separator','(')
            popXML()
            gl.currentLocation+=1
            assignment_expression()
            if(gl.value[gl.currentLocation]==')'):
                pushXML('separator',')')
                popXML()
                gl.currentLocation+=1
                code_blocks()
            else:
                print("while_expression: ) ERROR")
                exit(1)
        else:
            print("while_expression: ( ERROR")
    else:
        print("while_expression: while ERROR")
    popXML()

def for_expression():
    print("for_expression")
    pushXML('for_expression')
    if(gl.value[gl.currentLocation]=='for'):
        pushXML('loop','for')
        popXML()
        gl.currentLocation+=1
        if(gl.value[gl.currentLocation]=='('):
            pushXML('separator','(')
            popXML()
            gl.currentLocation+=1
            declare_expression()
            if(gl.value[gl.currentLocation]==';'):
                pushXML('separator',';')
                popXML()
                gl.currentLocation+=1
                assignment_expression()
                if(gl.value[gl.currentLocation]==';'):
                    pushXML('separator',';')
                    popXML()
                    gl.currentLocation+=1
                    assignment_expression()
                    if(gl.value[gl.currentLocation]==')'):
                        pushXML('separator',')')
                        popXML()
                        gl.currentLocation+=1
                        code_blocks()
                    else:
                        print("for_expression: assignment_expression ) ERROR")
                        exit(1)
                else:
                        print("for_expression: assignmen_expression ; ERROR")
                        exit(1)
            else:
                print("for_expression: declare_expression ; ERROR")
                exit(1)
        else:
            print("for_expression: ( ERROR")
            exit(1)
    else:
        print("for_expression: for ERROR")
        exit(1)
    popXML()
def if_expression():
    print("if_expression")
    pushXML('if_expression')
    if(gl.value[gl.currentLocation]=='if'):
        pushXML('switch','if')
        popXML()
        gl.currentLocation+=1
        if(gl.value[gl.currentLocation]=='('):
            pushXML('separator','(')
            popXML()
            gl.currentLocation+=1
            assignment_expression()
            if(gl.value[gl.currentLocation]==')'):
                pushXML('separator',')')
                popXML()
                gl.currentLocation+=1
                code_blocks()
                if(gl.value[gl.currentLocation]=='else'):
                    pushXML('switch','else')
                    popXML()
                    gl.currentLocation+=1
                    code_blocks()
            else:
                print("if_expression: ) ERROR")
                exit(1)
        else:
            print("if_expression: ( ERROR")
            exit(1)
    else:
        print("if_expression: if ERROR")
        exit(1)
    popXML()

def return_expression():
    print("return_expression")
    pushXML('return_expression')
    if(gl.value[gl.currentLocation]=='return'):
        pushXML('return','return')
        popXML()
        gl.currentLocation+=1
        assignment_expression()
    else:
        print("return_expression: return ERROR")
    popXML()

if __name__ == "__main__":
    readXML(sys.argv[1])
    print(gl.length)
    print(gl.value)
    print(gl.type)
    program()
    if(gl.currentLocation>=gl.length):
        print("ACC")
    with open(sys.argv[2],'w',encoding='UTF-8') as fp:
        dom.writexml(fp,indent=' ',addindent='\t',newl='\n',encoding='UTF-8')