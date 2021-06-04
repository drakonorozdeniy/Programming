import sys

import pygame
import random
import math
import json,operator
import requests
import pyHook




pygame.init()

display_width = 800
display_height = 600

lock=True
hi=99


def res_path(relative):
    if getattr(sys, 'frozen', False) and hasattr(sys, '_MEIPASS'): # if you are running in a |PyInstaller| bundle
        return os.path.join(sys._MEIPASS, relative)	           # возвращаем абсолютный путь с учётом 
                                                                   # директории временной распаковки
    return relative #path.join(os.getcwd(), relative)

i=0

x=400
y=100
display = pygame.display.set_mode((display_width, display_height))
spider_stay = pygame.image.load('images/spiderman_1.png')
spider_fly = pygame.image.load((res_path('images/spider_swing.png')))

spawn_drop=True

bitcoin_foto = pygame.image.load('images/bitcoin.png')

over_flow=False

pygame.display.set_caption('SPIDER-MAN')

icon=pygame.image.load('images/spider_had.png')
pygame.display.set_icon(icon)



pygame.mixer.music.load('sounds/Panthurr - Woof Pt 1 (special version for indyuk).mp3')
pygame.mixer.music.set_volume(0.03)

coin_sound= pygame.mixer.Sound('sounds/coinsound.mp3')
coin_sound.set_volume(0.07)


user_width = 70
user_height = 79
user_x = 330
user_y = 150
Frame1=pygame.image.load('images/hightscore.png')
magma_height=27
magma_width=27


dump = False

make_jump = False

window=True

img_our=0

def uMad(event):
    return False

def TrueMad(event):
    return True

hm = pyHook.HookManager()


jump_counter=30
dot_width = 30
dot_height = 30
dot_x = display_width - 50
dot_y = display_height - dot_height - 550

dot_img = [pygame.image.load('images/0.png'),pygame.image.load('images/1.png'),pygame.image.load('images/2.png'),
           pygame.image.load('images/3.png'),pygame.image.load('images/4.png'),pygame.image.load('images/5.png'),
           pygame.image.load('images/6.png'),pygame.image.load('images/7.png'),pygame.image.load('images/8.png'),
           pygame.image.load('images/9.png'),pygame.image.load('images/10.png'),pygame.image.load('images/11.png'),
           pygame.image.load('images/12.png'),pygame.image.load('images/13.png'),pygame.image.load('images/14.png'),
           pygame.image.load('images/15.png'),pygame.image.load('images/16.png'),pygame.image.load('images/17.png'),
           pygame.image.load('images/18.png'),pygame.image.load('images/19.png'),pygame.image.load('images/20.png'),
           pygame.image.load('images/21.png'),pygame.image.load('images/22.png'),pygame.image.load('images/23.png'),
           pygame.image.load('images/24.png'),]

coin_img = [pygame.image.load('images/coin_1.png'),pygame.image.load('images/coin_2.png'),
            pygame.image.load('images/coin_3.png'),pygame.image.load('images/coin_4.png'),
            pygame.image.load('images/coin_5.png'),pygame.image.load('images/coin_6.png')]

spider_fall_img = pygame.image.load('images/spiderman_fall.png')

window_speak=pygame.image.load('images/window.png')

window_speak2=pygame.image.load('images/window_2.png')

window_speak3=pygame.image.load('images/window_3.png')

magmablock=pygame.image.load('images/magmablock.jpg')
left=False
right=False
Count=0
scroll=False
drop =False
xi=10
walkRight=[pygame.image.load('images/spiderman_right_2.png'),pygame.image.load('images/spiderman_right_3.png'),
           pygame.image.load('images/spiderman_right_4.png')]
walkLeft =[pygame.image.load('images/spiderman_left_2.png'),pygame.image.load('images/spiderman_left_3.png'),
           pygame.image.load('images/spiderman_left_4.png')]

bkgd=pygame.image.load('images/wallpaper.jpg').convert()

img_coin=0
line_tick=55
line_text='->'
tick=80
text="Press Tab to play again, Esc to exit"
img_counter = 0

wed= pygame.image.load('images/web.png')
clock = pygame.time.Clock()
fire1 = [display_width + 30, display_width-770, 40, 40, 1.5]
fire2 = [display_width + 300, display_width-770, 40, 40, 1.5]
fire3 = [display_width + 600, display_width-770, 40, 40, 1.5]


bitcoin1 = [display_width + 30, display_height-300, 20, 20, 1.5]
bitcoin2 = [display_width + 300, display_height-200, 20, 20, 1.5]

angleV=0
reiting= 0
pop = False
pop2 = False

mark=0
need_input = False
input_text = '|'
input_tick = 80
array=[]

sigma=0
magma_move=False
ki=300
S=300
k=0
fly = False


class Button:
    def __init__(self, width, height,innactiva_clr,active_clr,color_text,font_type):
        self.width=width
        self.height=height
        self.inactive_clr=innactiva_clr
        self.active_clr=active_clr
        self.color_text=color_text
        self.font_type=font_type

    def draw(self,x,y,message, action=None, font_size=30):
        mouse = pygame.mouse.get_pos()
        click=pygame.mouse.get_pressed()

        if  x < mouse[0]< x+self.width  and y<mouse[1]< y+self.height:
            pygame.draw.rect(display,self.active_clr ,(x,y,self.width,self.height +15 ),4)

            if click[0] == 1:
                if action is not None:
                    if action ==pygame.quit:
                        pygame.quit()
                        quit()
                    else :
                        action()

        else:
            pygame.draw.rect(display,  self.inactive_clr, (x, y, self.width, self.height +15),4)

        print_text(message=message,x=x+10,y=y+10,font_type=self.font_type,font_size=font_size,font_color=self.color_text)

class Board(pygame.sprite.Sprite):
    def __init__(self):
        pygame.sprite.Sprite.__init__(self)
        self.image = pygame.Surface((800, 600))
        self.image.fill((13,13,13))
        self.image.set_colorkey((13,13,13))
        self.rect = self.image.get_rect()
        self.font = pygame.font.Font("fonts/dpcomic.ttf", 20)

    def add(self, letter, pos):
        if letter =='A':
            s = self.font.render(letter, True, (255, 0, 255))
        elif letter =='D':
            s = self.font.render(letter, True, (255, 105, 180))
        elif letter =='W':
            s = self.font.render(letter, True, (255, 182, 193))
        elif letter == '2':
            s = self.font.render(letter, True, (255, 0, 0))
        elif letter == '0':
            s = self.font.render(letter, True, (255, 0, 0))
        elif letter == '1':
            s = self.font.render(letter, True, (255, 0, 0))
        else :
            s = self.font.render(letter, True, (240, 230, 140))
        self.image.blit(s, pos)


def uMad(event):
    return False


class Cursor(pygame.sprite.Sprite):
    def __init__(self, board,X,Y):
        pygame.sprite.Sprite.__init__(self)
        self.image = pygame.Surface((10, 20))
        self.image.fill((255,255,255))
        self.text_height = 17
        self.text_width = 10
        self.weight=X
        self.height=Y
        self.rect = self.image.get_rect(topleft=(X, Y))
        self.board = board
        self.text = ''
        self.cooldown = 0
        self.cooldowns = {'.': 12,
                        '[': 18,
                        ']': 18,
                        ' ': 3,
                        '\n': 20}

    def write(self, text):
        self.text = list(text)


    def update(self):
        if not self.cooldown and self.text:
            letter = self.text.pop(0)
            if letter == '\n':
                self.rect.move_ip((0, self.text_height+10))
                self.rect.x = XI


            else:
                self.board.add(letter, self.rect.topleft)
                self.rect.move_ip((self.text_width, 0))
            self.cooldown = self.cooldowns.get(letter, 8)

        if self.cooldown:
            self.cooldown -= 1
        if (len(self.text)==0):
            line_print(680,238)

def show_menu():
    menu_bckgr=pygame.image.load('images/background_2.png')

    start_btn = Button(225,60,(0,0,0),(255,0,0),(255,115,0),'fonts/karma.otf')
    quit_bnt=Button(100, 60,(0,0,0),(255,0,0),(255,115,0),'fonts/karma.otf')
    show=True
    while show:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                quit()
        display.blit(menu_bckgr,(0,0))
        start_btn.draw(290,250,'START GAME',start_game,40)
        quit_bnt.draw(350,350,'QUIT', pygame.quit,40)

        pygame.display.update()
        clock.tick(60)


XI=450
YE=190


come=0

up_k=0

all_sprites = pygame.sprite.Group()
a0 = Board()
A0 = Cursor(a0,XI,YE)

a1 = Board()
A1=Cursor(a1,XI,170)

a2= Board()
A2=Cursor(a2,XI,170)

a3=Board()
A3=Cursor(a3,XI,170)

a4=Board()
A4=Cursor(a4,XI,170)

A0.write('Hi, my name is Spider-man.\nI need you to give me a li-\nttle help.')
all_sprites.add(A0,a0)

react=True

def start_game():
    while game_cycle():
        pass

def game_cycle():
    global  user_y,user_x,make_jump,left,right,magma_move,scroll,k,XI,YE,react,come,window,up_k,dump
    game = True

    pygame.mixer.music.play(-1)
    not_fall=False
    while game:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                quit()
            if event.type == pygame.MOUSEBUTTONDOWN and event.button == 1:
                react=False
                come += 1

                if come == 1:
                    all_sprites.add(A1, a1)
                    A1.write('It is 2021, the time of bitcoins\npopularity, and with your help, I\ncan earn money and buy a ring\nfor Mary Jane.')

                    all_sprites.remove(A0, a0)
                    react = True
                if come == 2 :
                    all_sprites.add(A2, a2)
                    A2.write('To move, use the keys: A, D, to\nmove left and right respective-\nly. I can also make jumps by pr\nessing the key: W.')
                    all_sprites.remove(A1,a1)
                    react= True

                if come == 3 :
                    all_sprites.add(A3,a3)
                    A3.write('To climb the web, use the mouse\nwheel and remember that I will \nclimb endlessly until you press\nthe key : SPACEBAR.')
                    all_sprites.remove(A2, a2)
                    react = True

                if come == 4 :
                    all_sprites.add(A4,a4)
                    A4.write('If you do not succeed, then you \nwill be offered to save the re\ncord. Good luck!')
                    all_sprites.remove(A3, a3)
                    react = True

                if come == 5:
                    window=False
                    hm.KeyAll = TrueMad
                    hm.HookKeyboard()

                ScrollBackground()
                x = draw_magma()
                sink_spider()
                draw_spider(left, right)
                omega = draw_array(scroll, k, not_fall)
                spider_fall(x, omega[0], omega[1], omega[2])
                text_score(25, 14)
                pygame.display.update()
            if event.type == pygame.MOUSEBUTTONDOWN and event.button == 4:
                k=1.5
            if event.type == pygame.MOUSEBUTTONDOWN and event.button == 5:
                k=-1.5
        keys = pygame.key.get_pressed()
        if keys[pygame.K_SPACE]:
            k=0
        if dump == True :
            k=0

        if keys[pygame.K_a] and user_x > 5:
            user_x -= 2
            left =True
            right=False
            magma_move = True
            scroll=True
        if keys[pygame.K_d] and user_x < 800 -user_width - 5:
            user_x += 2
            left=False
            right=True
            magma_move=True
            scroll=True
        if keys[pygame.K_w]:
            make_jump=True
        if make_jump:
            jump()
        if (keys[pygame.K_d]==0 and keys[pygame.K_a]==0):
            left=False
            right=False

        ScrollBackground()
        x=draw_magma()
        sink_spider()
        draw_spider(left,right)
        omega=draw_array(scroll,k,not_fall)
        spider_fall(x,omega[0],omega[1],omega[2])

        if dead_spider(user_x,user_y):
            pygame.mixer.music.stop()
            game = False
        text_score(25,14)

        pygame.display.update()
        clock.tick(60)
    return game_over()

def sink_spider():
    global user_y,user_x,fly,drop,spawn_drop,react,window,up_k,come,over_flow
    y=271
    if spawn_drop:
        hm.KeyAll = uMad
        hm.HookKeyboard()
        if (user_y!=y):
            display.blit(spider_fly,(user_x,user_y))
            drop = True
            user_y+=1
        if (user_y==y):
            drop=False
            spawn_drop=False
    if user_y==y and window:
        if come==0:
            display.blit(window_speak,(400,175))
        if come>=1:
            display.blit(window_speak2,(395,152))

        if react:
            all_sprites.update()
            all_sprites.draw(display)


def move(array):
    if array[0] >= -1*array[0]:
         draw_dot(array[0],array[1])
         array[0] -= array[4]
         return array[0]
    else:
        array[0] = display_width + 100 + random.randrange(-80, 60)
        return array[0]


def draw_magma():
    global S,magma_move,ki
    display.blit(magmablock, (S, display_height - 259))
    display.blit(magmablock, (S + 27, display_height - 259))
    display.blit(magmablock, (S + 54, display_height - 259))
    display.blit(magmablock, (S + 81, display_height - 259))
    display.blit(magmablock, (S + 108, display_height - 259))
    display.blit(magmablock, (S + 135, display_height - 259))
    display.blit(magmablock, (S + 162, display_height - 259))
    display.blit(magmablock, (S + 189, display_height - 259))
    display.blit(magmablock, (S + 216, display_height - 259))
    display.blit(magmablock, (S + 235, display_height - 259))
    if magma_move==False:
        S=ki
    else :
        S-=1
        ki=S
    return (S+235)


def ScrollBackground():
    global sigma,scroll,mark

    rel_x = sigma % bkgd.get_rect().width
    display.blit(bkgd,(rel_x-bkgd.get_rect().width,0))
    if (rel_x < display_width):
        display.blit(bkgd,(rel_x,0))
    if scroll==False :
        sigma = mark
    else :
        sigma-=1
        mark=sigma


def  draw_array(scroll,k,not_fall):
    global user_x,user_y,angleV,pop,pop2
    b1=False
    b2=False
    b3=False
    if scroll :
        x1=move(fire1)
        x2=move(fire2)
        x3=move(fire3)
        kesh1 = move_bitcoin(bitcoin1,pop)
        kesh2 = move_bitcoin_2(bitcoin2,pop2)
        pop=score(kesh1[0],kesh1[1])
        pop2=score(kesh2[0],kesh2[1])
        b1=swing(x1,k,not_fall)
        b2=swing(x2,k,not_fall)
        b3=swing(x3,k,not_fall)
    return (b1,b2,b3)


def swing(X,k,not_fall):
    global user_x, user_y,angleV,fly,dump;
    pressed = pygame.mouse.get_pressed()
    pos = pygame.mouse.get_pos()
    gravity = 0.2
    x = user_x - X
    len = math.sqrt(pow(X - user_x, 2) + pow((display_width - 770) - user_y, 2))
    if (pressed[0]) and (X <= pos[0] <= X + 50) and ((display_width - 770) <= pos[1] <= ((display_width - 770) + 50)) and (len<=400):
        if user_y <= 100:
            user_y=100
        len+=k
        angle = math.asin(x/len)
        forse = gravity*(math.sin(angle))
        angleA = (-1*forse)/len
        angleV = angleV + angleA
        angle += angleV
        user_x = len*math.sin(angle)+X
        if user_y <= 100:
            user_y=100
            angleV=0
            dump=True
        else :
            user_y = len*math.cos(angle)+(display_width-770)
            dump=False


        fly = True
        not_fall=True
        pygame.draw.line(display, (225, 232, 234), (user_x+65, user_y), (pos[0], pos[1]), 4)
        display.blit(spider_fly, (user_x, user_y))
    else :
        not_fall=False
    return not_fall


def text_score(x,y):
    display.blit(bitcoin_foto,(x,y))
    print_text(str(reiting), x+29, y+26,font_size=14,font_type='fonts/PressStart2P-Regular.ttf',font_color=(255,255,255))


def spider_fall(fall,not_fall1,not_fall2,not_fall3):
    global user_y,drop

    if not_fall1==True :
        if fall<user_x :
            not_fall2=True
            not_fall3=True

    if not_fall3==True :
        if fall < user_x :
            not_fall1=True
            not_fall2=True

    if not_fall2==True :
        if fall<user_x :
            not_fall1=True
            not_fall3=True


    if not_fall1==False:
        if fall<user_x:
            user_y += 1
            drop=True
            display.blit(spider_fly,(user_x,user_y))
        else :
            drop=False


    if not_fall1==True :
        if fall<user_x :
            not_fall2=True
            not_fall3=True

    if not_fall2 == False:
        if fall < user_x:
            user_y += 1
            drop = True
            display.blit(spider_fly, (user_x, user_y))

        else:
            drop = False

    if not_fall3 == False:
        if fall < user_x:
            user_y += 1
            drop = True
            display.blit(spider_fly, (user_x, user_y))
        else:
            drop = False


def draw_coin(x, y):
    global img_coin
    if img_coin == 60:
        img_coin = 0
    display.blit(coin_img[img_coin//10], (x, y))
    img_coin += 1


def draw_spider(left,right):
    global user_x,user_y,Count,make_jump,drop,fly
    if Count==18:
        Count = 0
    if left and make_jump==False and  fly==False and drop==False :
        display.blit(walkLeft[Count//6],(user_x,user_y))
        Count +=1
    if right and make_jump==False and  fly==False  and drop==False:
        display.blit(walkRight[Count//6],(user_x,user_y))
        Count +=1
    if (make_jump) == True  and  fly==False:
        display.blit(spider_fly,(user_x,user_y))

    elif (left==False) and (right==False) and (fly==False) and (drop==False) :
        display.blit(spider_stay,(user_x,user_y))


def draw_dot(x, y):
    global img_counter
    if img_counter == 350:
        img_counter = 0

    display.blit(dot_img[img_counter//15],(x,y))
    img_counter += 1


def move_bitcoin(array,pop):
    global avangard
    if array[0] >= -1*array[0]:
        if pop == True:
            pygame.mixer.Sound.play(coin_sound)
            array[0]=-30
            draw_coin(array[0],array[1])
            array[0] -= array[4]
        else:
            draw_coin(array[0], array[1])
            array[0] -= array[4]
    else:
        array[0] = display_width + 100 + random.randrange(-80, 80)
        array[1] =200 + random.randrange(-25,100)
    return(array[0],array[1])


def move_bitcoin_2(array,pop2):
    global avangard
    if array[0] >= -1*array[0]:
        if pop2 == True:
            pygame.mixer.Sound.play(coin_sound)
            array[0]=-30
            draw_coin(array[0], array[1])
            array[0] -= array[4]
        else:
            draw_coin(array[0], array[1])
            array[0] -= array[4]
    else:
        array[0] = display_width + 100 + random.randrange(-80, 80)
        array[1] =200 + random.randrange(-25,100)
    return(array[0],array[1])


def score(money_x,money_y):
    global reiting
    if (user_y + user_height >=money_y) and (((user_y + user_height)-money_y)<=109) :
        if money_x<=user_x<=money_x+dot_width:
            reiting += 1
            return True
        elif money_x <= user_x+user_width <= money_x + dot_width:
            reiting += 1
            return True
    else:
        return False


def print_text(message,x,y,font_color=(255,255,255),font_type = "fonts/font.otf",font_size=30):
    font_type= pygame.font.Font(font_type,font_size)
    text=font_type.render(message,True,font_color)
    display.blit(text,(x,y))


def game_over():
    stopped=True
    got_name= False
    global user_x,user_y,reiting,fire1,fire2,fire3,bitcoin1,bitcoin2,fly,S,magma_move,scroll,drop,ki,angleV,spawn_drop
    while stopped:
        for event in pygame.event.get():
            if event.type==pygame.QUIT:
                pygame.quit()
                quit()
        scroll=False
        ScrollBackground()
        print_text("GAME OVER",150,60,font_type='fonts/Thirteen-Pixel-Fonts.ttf',font_size=70,font_color=(255,34,24))
        Newgame()
        print_text("Your record : ",250,200, font_type='fonts/Thirteen-Pixel-Fonts.ttf',font_size=40,font_color=(255,223,0))
        text_score(570,209)
        if not got_name:
            print_text("Enter your name :",50,300,font_color=(255,0,233),font_type='fonts/Thirteen-Pixel-Fonts.ttf',font_size=40)
            name = get_input(482,295)
            if name:
                got_name = True

        keys=pygame.key.get_pressed()
        if keys[pygame.K_TAB]:
            user_x = 350
            user_y =  display_height - 259-70
            fire1 = [display_width + 30, display_width - 770, 30, 30, 1.5]
            fire2 = [display_width + 300, display_width - 770, 30, 30, 1.5]
            fire3 = [display_width + 600, display_width - 770, 30, 30, 1.5]

            bitcoin1 = [display_width + 30, display_height - 300, 20, 20, 1.5]
            bitcoin2 = [display_width + 300, display_height - 200, 20, 20, 1.5]
            reiting=0
            S=300
            fly=False
            magma_move=False
            scroll=False
            drop=False
            ki=300
            angleV = 0
            return True
        if keys[pygame.K_ESCAPE]:
            return False
        TaibleRanting = Button(120, 35,(138,43,226),(255,140,0),(225,34,24),'fonts/papercut.ttf')
        TaibleRanting.draw(40, 440, 'Records', reiting_score,27)
        pygame.display.update()
        clock.tick(120)


def reiting_score():
    j_2 = get()
    sort(j_2)
    display.blit(Frame1,(250,25))
    x=305
    y=180
    for i in range (len(j_2)) :
        if (i>8) :
            break
        else:
            print_text(j_2[i]['username'],x+125,y,font_color=(127,255,212),font_type='fonts/Thirteen-Pixel-Fonts.ttf',font_size=30)
            print_text(str(j_2[i]['score']),x+350,y,font_color=(0,255,127),font_type='fonts/Thirteen-Pixel-Fonts.ttf',font_size=30)
            if (i+1)==1  :
                pygame.draw.rect(display, (255, 215, 0), pygame.Rect(x, y + 5, 30, 30), border_radius=3)
            elif (i+1)==2:
                pygame.draw.rect(display,(192,192,192),pygame.Rect(x,y+5,30,30),border_radius=3)
            elif (i+1)==3 :
                pygame.draw.rect(display, (205, 127, 50), pygame.Rect(x, y + 5, 30, 30), border_radius=3)
            elif (i+1)==9 :
                pygame.draw.rect(display, (205, 127, 50), pygame.Rect(x, y + 50, 30, 30), border_radius=3)

        print_text(str(i+1),x+6,y+9,font_color=(0,0,0),font_type='fonts/ka1.ttf',font_size=20)
        pygame.draw.rect(display, (0, 0, 0), pygame.Rect(x, y + 5, 31, 31), width=1, border_radius=3)

        print_text(j_2[i]['username'],x+125,y,font_color=(127,255,212),font_type='fonts/Thirteen-Pixel-Fonts.ttf',font_size=30)
        print_text(str(j_2[i]['score']),x+350,y,font_color=(0,255,127),font_type='fonts/Thirteen-Pixel-Fonts.ttf',font_size=30)
        y+=47


def jump():
    global user_y, make_jump, jump_counter

    if jump_counter >= -30:
        user_y -= jump_counter / 5
        jump_counter -=1
    else :
        jump_counter = 30
        make_jump = False


def dead_spider(x,y):
    if (x>=800) or  (y>=600) or (x<=-70) or (y<=-79):
        return True
    else:
        return False


def Newgame():
    global tick ,text

    print_text(message=text, x=20, y=570, font_size=20)

    tick = tick -1

    if tick==0:
        text = text[:-36]
    if tick==-80:
        text += "Press Tab to play again, Esc to exit"
        tick = 80


def line_print(x,y):
    global line_tick ,line_text

    print_text(message=line_text, x=x, y=y, font_size=52,font_color=(255,140,0))

    line_tick = line_tick -1

    if line_tick==0:
        line_text = line_text[:-2]
    if line_tick==-55:
        line_text += "->"
        line_tick = 55


def get_input(x,y):
    global need_input, input_text,input_tick, reiting

    input_rect = pygame.Rect(x,y,250,62)

    pygame.draw.rect(display,(255,255,255),input_rect)
    pygame.draw.rect(display, (255,0,223), (x,y,252,64),1)
    mouse=pygame.mouse.get_pos()
    click=pygame.mouse.get_pressed()

    if input_rect.collidepoint(mouse[0], mouse[1]) and click[0]:
        need_input = True

    if need_input:
        for event in pygame.event.get():
            if need_input and event.type == pygame.KEYDOWN:
                input_text = input_text.replace('|','')
                input_tick = 80

                if event.key == pygame.K_RETURN:
                    need_input=False
                    message=input_text
                    input_text = ''
                    post(message,reiting)
                    return message
                elif event.key == pygame.K_BACKSPACE:
                    input_text = input_text[:-1]
                else:
                    if len(input_text) < 10:
                        input_text += event.unicode

                input_text +='|'

    if len(input_text):
        print_text(message=input_text,x=input_rect.x+10,y=input_rect.y +10,font_size=50,font_color=(0,0,0),)

    input_tick -= 1

    if input_tick ==0:
        input_text = input_text[:-1]
    if input_tick == -80:
        input_text +='|'
        input_tick = 80
    return None

def post(value1, value2):
    host = 'http://localhost:3000'
    send_data={'username': value1, 'score': value2}
    requests.post(host, data=send_data)

def get():
    host = 'http://localhost:3000'
    response = requests.get(host)
    data = response.json()
    return data

def sort(j_pop):
    j_pop.sort(key=operator.itemgetter("score"), reverse=True)


show_menu()
#pygame.quit()
#quit()

