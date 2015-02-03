Mamemaki
========

[![Build Status](https://travis-ci.org/koturn/Mamemaki.png)](https://travis-ci.org/koturn/Mamemaki)

鬼は外！福は内！
あなたのパソコンの中の鬼を追い出し，厄除けをしましょう！

※ただのモンテカルロ法による円周率の計算を行うプログラムです．

## 元ネタ

<blockquote class="twitter-tweet" lang="ja"><p>計算機内の鬼を追い出すべく、モンテカルロ法を応用した豆まきルーチン（副産物で円周率が近似的に求まる）</p>&mdash; あかやぎ (@akayagi) <a href="https://twitter.com/akayagi/status/562533440336048128">2015, 2月 3</a></blockquote>
<script async src="//platform.twitter.com/widgets.js" charset="utf-8"></script>


## Usage

```sh
$ ./omikuji
```


## Build

Use [Makefile](Makefile).

###### Release version

```sh
$ make
```

###### Debug version

```sh
$ make
```

If you want to build with MSVC, use [msvc.mk](msvc.mk).
[msvc.mk](msvc.mk) is written for nmake.

###### Release version

```sh
> nmake /f msvc.mk
```

###### Debug version

```sh
> nmake /f msvc.mk DEBUG=true
```


## References

- [元ネタ](https://twitter.com/akayagi/status/562533440336048128)
- [Xorshift RNGs](http://www.jstatsoft.org/v08/i14/paper)
- [ランダム: 小川暇つぶしチラ裏](http://ogawa-sankinkoutai.seesaa.net/article/108848981.html)


## LICENSE

This software is released under the MIT License, see [LICENSE](LICENSE).
