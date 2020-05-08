#!/usr/bin/env bash

## Bitbucket
#commit=${BITBUCKET_COMMIT:-$(git rev-parse HEAD)}

# Gitlab
commit=${CI_COMMIT_SHA:-$(git rev-parse HEAD)}

# Define ALLOWED_RELEASE_BRANCH in VCS pipelines secret variables.
branch=${ALLOWED_RELEASE_BRANCH:-master}

if ! git branch -a --contains "${commit}" | grep -e "^[* ]*remotes/origin/${branch}\$"
then
  echo -e "###\n### Not on ${branch}. Only ${branch} commits can be released.\n###"
  exit 1
else
  echo -e "###\n### Releasing of ${commit} on ${branch}\n###"
fi

version=$(./scripts/version.py get)
version_file=VERSION
echo ${version} > ${version_file}

echo "Pushing detached tag of new version"
git add ${version_file}
git commit -m "Release version ${version}"
git tag  -a ${version} -m "Release version ${version} tag"
git push origin ${version}

echo "Pushing new version to ${branch}"
git fetch origin "${branch}:${branch}" || git pull
git checkout "${branch}"
# Parameter of the script
release_type=${1}
./Scripts/version.py inc-${release_type}

next_working_version=$(./Scripts/version.py get --with-pre-release-placeholder)
git add ${version_file}
git commit -m "Incrementing working version to ${next_working_version} after ${version} release."
git push origin ${branch}
