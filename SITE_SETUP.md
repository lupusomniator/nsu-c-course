# Публикация и обновление сайта

Документация собирается из Markdown в корне репозитория. Главная страница —
`README.md`, остальные страницы получают адреса из `permalink` в начале файла.

Ожидаемый адрес: https://lupusomniator.github.io/nsu-c-course/

## Первое включение GitHub Pages

1. Войдите в GitHub под аккаунтом с правом управления репозиторием.
2. Откройте [Settings → Pages](https://github.com/lupusomniator/nsu-c-course/settings/pages).
3. В **Build and deployment → Source** выберите **GitHub Actions**.
4. Отправьте подготовленные коммиты в `main`.
5. Во вкладке [Actions](https://github.com/lupusomniator/nsu-c-course/actions)
   дождитесь успешного workflow **Documentation site**: сначала `build`, затем `deploy`.

Если коммиты уже отправлены до включения Pages, откройте этот workflow и нажмите
**Run workflow → main → Run workflow**. Если среда `github-pages` требует
ручного одобрения, GitHub покажет кнопку **Review deployments**.

Для отправки через GitHub CLI можно настроить вход так:

```bash
gh auth login --hostname github.com --git-protocol https --web --scopes workflow
gh auth setup-git
git push origin main
```

Разрешение `workflow` нужно для отправки файла `.github/workflows/pages.yml`.
Персональный токен в файлы репозитория или настройки workflow добавлять не нужно:
сборка использует автоматический `GITHUB_TOKEN` с разрешениями на публикацию Pages.

## Как обновлять материалы

1. Отредактируйте нужный `.md`.
2. Сохраните изменения в коммит и отправьте их в `main`.
3. GitHub Actions соберёт и опубликует новую версию.

Для pull request выполняются сборка и проверка ссылок. Публикация выполняется
только из `main`. Не отправляйте `_site/`, `vendor/` и `.bundle/`: они исключены
через `.gitignore`.

Чтобы добавить страницу, создайте Markdown-файл с заголовком настроек:

```yaml
---
title: Название раздела
nav_order: 7
permalink: /new-section/
---
```

После него пишите обычный Markdown. `nav_order` задаёт место в меню, `permalink`
— постоянный адрес. В ссылках между документами используйте имена `.md`, например
`[Сборка](how_to_cmake.md)`: плагин преобразует их в адреса страниц сайта.

При переименовании заголовка проверяйте ссылки с `#раздел`: автоматическая проверка
останавливает сборку, если раздел или локальный файл отсутствует.

## Локальный просмотр

Нужны Ruby версии из `.ruby-version`, Bundler и Python 3.9 или новее.
Из корня репозитория:

```bash
bundle config set --local path vendor/bundle
bundle install
bundle exec jekyll serve --host 127.0.0.1
```

Откройте http://127.0.0.1:4000/nsu-c-course/.

Проверка перед отправкой:

```bash
bundle exec jekyll build --strict_front_matter
python3 scripts/check_site.py _site /nsu-c-course
```

`Gemfile.lock` фиксирует версии зависимостей для локальной сборки и CI. После
осознанного обновления зависимостей включайте его изменения в коммит.

## Если публикация не прошла

- Ошибка в `build`: откройте журнал; исправьте Markdown, ссылки или зависимости.
- Ошибка в `deploy`, связанная с Pages: проверьте источник **GitHub Actions**
  в Settings → Pages и права workflow / правила среды `github-pages`.
- `git push` отклонён: проверьте аккаунт и права на репозиторий. Не используйте
  `--force`; если `main` изменился на сервере, сначала согласуйте локальную историю.

Настройки сайта находятся в `_config.yml`. Если изменятся владелец или название
репозитория, обновите `url`, `baseurl`, ссылки на GitHub и аргумент базового пути
в `.github/workflows/pages.yml`.

Этот файл служит памяткой для преподавателя и исключён из публикуемого сайта.
