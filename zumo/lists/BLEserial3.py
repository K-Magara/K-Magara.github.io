import asyncio
from bleak import BleakClient

address = "C4:42:29:32:79:2D"
UUID = "FEEDAA02-C497-4476-A7ED-727DE7648AB1"

async def run(address, loop):
	async with BleakClient(address, loop=loop) as client:
		x = await client.is_connected()
		print("Connected: {0}".format(x))
		await client.write_gatt_char(UUID,str(1))	## send

loop = asyncio.get_event_loop()
loop.run_until_complete(run(address, loop))
