import sys
import asyncio
from bleak import BleakClient
import pygame
from pygame.locals import *

pygame.init()
screen = pygame.display.set_mode((320, 320))

address = "C4:42:29:32:79:2D"
UUID = "FEEDAA02-C497-4476-A7ED-727DE7648AB1"

async def run(address, loop):
	async with BleakClient(address, loop=loop) as client:
		x = await client.is_connected()
		print('BLE Connected: {0}'.format(x))

		active = True
		while active:
			for e in pygame.event.get():
				if e.type == QUIT:
					active = False
					break
				if e.type == KEYDOWN:
					if e.key == K_ESCAPE:
						print('ESC program end.')
						active = False
						break
					elif e.key == K_UP:
						print('Front')
						w = "1"		# front
					elif e.key == K_DOWN:
						print('Back')
						w = "2"		# back
					elif e.key == K_RIGHT:
						print('Right')
						w = "3"		# right
					elif e.key == K_LEFT:
						print('Left')
						w = "4"		# left
					elif e.key == K_SPACE:
						print('Space')
						w = "0"		# stop
					await client.write_gatt_char(UUID, w)
				pygame.time.wait(100)

loop = asyncio.get_event_loop()
loop.run_until_complete(run(address, loop))
