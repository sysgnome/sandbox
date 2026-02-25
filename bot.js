const mineflayer = require('mineflayer');

const bot = mineflayer.createBot({
    host: 'localhost',
    port: 57133,
    username: 'Bot',
});

bot.on('chat', (username, message) => {
    if (username === bot.username) return;
    bot.chat(message);
});

bot.on('kicked', console.log);
bot.on('error', console.log);
